// https://leetcode.com/problems/robot-collisions/description/?envType=daily-question&envId=2026-04-01

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int, pair<int, char>>>ds;
        unordered_map<int, int>mpp;
        for(int i = 0; i < positions.size(); i++) {
            ds.push_back({positions[i], {healths[i], directions[i]}});            
            mpp[positions[i]] = i;
        }


        sort(ds.begin(), ds.end());

        stack<pair<int, pair<int, char>>>st;

        for(auto it:ds) {
            int p = it.first;
            int h = it.second.first;
            char d = it.second.second;
            if(st.empty() || d == 'R' || st.top().second.second == d) {
                st.push({p, {h, d}});
                continue;
            }    

            while(!st.empty() && h > 0) {
                int top_p = st.top().first;
                int top_h = st.top().second.first;
                char top_d = st.top().second.second;
                st.pop();

                if(top_d == 'L') {
                    st.push({top_p, {top_h, top_d}});
                    break;
                }

                if(top_h == h) {
                    h = 0;
                    break;
                }
                else if(top_h < h)   h--; 
                else {
                    st.push({top_p, {top_h-1, top_d}});
                    h = 0;
                }
            }

            if(h > 0)   st.push({p, {h, d}});
        }

        vector<pair<int, int>>temp;
        while(!st.empty()) {
            int p = st.top().first;
            int h = st.top().second.first;
            temp.push_back({mpp[p], h});
            st.pop();
        }

        sort(temp.begin(), temp.end());

        vector<int>ans;
        for(auto it:temp)   ans.push_back(it.second);

        return ans;
    }
};