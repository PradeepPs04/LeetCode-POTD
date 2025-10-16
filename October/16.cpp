// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/?envType=daily-question&envId=2025-10-16

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int>mpp;
        for(auto it:nums) {
            int md = (it % value + value) % value;
            mpp[md]++;
        }

        int ans = 0;
        int req = 0;

        while(true) {
            if(mpp[req] > 0)    {
                mpp[req]--;
                ans++;
            } else break;

            req = (req + 1) % value;
        }

        return ans;
    }
};