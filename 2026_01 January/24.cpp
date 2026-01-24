// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/?envType=daily-question&envId=2026-01-24

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size()-1;

        int maxi = INT_MIN;
        while(left < right) maxi = max(maxi, nums[left++] + nums[right--]);

        return maxi;
    }
};