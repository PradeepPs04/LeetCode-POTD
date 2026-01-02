// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/?envType=daily-question&envId=2026-01-02

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // Since one element appears in exactly 50% of the array, it cannot stay more than 2 indices apart everywhere.
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == nums[(i+1)%n] || nums[i] == nums[(i+2)%n])    return nums[i];
        }

        return -1;
    }
};