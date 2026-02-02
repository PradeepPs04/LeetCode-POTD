// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/description/?envType=daily-question&envId=2026-02-02

#define ll long long
#define P pair<ll, int>
class Solution {
public:
    ll minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        set<P>kMinimum; // (K-1) smallest elements in a window 
        set<P>remaining; // reamining element of window

        ll result = LONG_MAX; // minium sum of (K-1) smallest elements in a window
        ll sum = 0; // sum or (K-1) smallest elements  

        //  make a window
        int i = 1;
        while(i - dist < 1) {
            kMinimum.insert({nums[i], i});
            sum += nums[i]; 

            // if more than k-1 element in 'Kminimum' set
            if(kMinimum.size() > k-1) {
                // remove the largest element
                P temp = *kMinimum.rbegin();
                sum -= temp.first; 
                kMinimum.erase(temp);

                // insert it into 'remaining' set
                remaining.insert(temp);
            }

            i++;
        }

        // slide the window
        while(i < n) {
            kMinimum.insert({nums[i], i});
            sum += nums[i];

            if(kMinimum.size() > k-1) {
                P temp = *kMinimum.rbegin();
                sum -= temp.first;
                kMinimum.erase(temp);
                remaining.insert(temp);
            }

            result = min(result, sum);

            // shift window right by 1
            // remove 'i-dist' element
            P remove = {nums[i-dist], i-dist};

            // if it's present in kMinimum set
            if(kMinimum.count(remove)) {
                kMinimum.erase(remove);
                sum -= remove.first;

                // if remaining set having any element
                // insert smallest from reamining into kMinimum
                if(!remaining.empty()) {
                    P temp = *remaining.begin();
                    kMinimum.insert(temp);
                    sum += temp.first;
                    remaining.erase(temp);
                }
            } else {
                // remove element from remaining set
                remaining.erase(remove);
            }

            i++;
        }

        return (ll)nums[0] + result;
    }
};