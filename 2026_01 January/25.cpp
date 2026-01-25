// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/?envType=daily-question&envId=2026-01-25
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mini = INT_MAX;

        int left= 0; 
        int right = k-1;

        while(right < nums.size()) {
            mini = min(mini, abs(nums[right++] - nums[left++]));
        }

        return mini;
    }
};
