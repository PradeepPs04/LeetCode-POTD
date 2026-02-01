// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description/?envType=daily-question&envId=2026-02-01

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];

        int s1 = INT_MAX;
        int s2 = INT_MAX;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] < s1) {
                s2 = s1;
                s1 = nums[i];
            } else s2 = min(s2, nums[i]);
        }

        ans += s1+s2;
        return ans;
    }
};