// https://leetcode.com/problems/minimum-distance-to-the-target-element/?envType=daily-question&envId=2026-04-13

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target)   mini = min(mini, abs(i-start));
        }

        return mini;
    }
};