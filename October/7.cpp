// https://leetcode.com/problems/avoid-flood-in-the-city/?envType=daily-question&envId=2025-10-07

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int>ans(rains.size(), 1);
        set<int>st; // stores indices of zeros (no rainy days)
        unordered_map<int, int>mpp; // store indices of non-zeros (rainy days)

        for(int i = 0; i < rains.size(); i++) {
            if(rains[i] == 0) {
                st.insert(i);
            } else {
                ans[i] = -1;
                // check if it's raining for the second time (flood situation)
                if(mpp.count(rains[i])) {
                    // there must be a no rainy day after the first rain on that lake
                    // so we can dry that lake
                    auto it = st.lower_bound(mpp[rains[i]]);
                    // if no such day found (then there will be a flood)
                    if(it == st.end())  return {};

                    // dry that lake
                    ans[*it] = rains[i];
                    // remove that day from set
                    st.erase(it);
                }

                // add rainy day to map
                mpp[rains[i]] = i;
            }
        }

        return ans;
    }
};