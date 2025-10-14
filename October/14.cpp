// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/?envType=daily-question&envId=2025-10-14

class Solution {
private:
    bool helper(vector<int>& nums, int i, int k) {
        // if substring of length k is not possible
        if(i + k > nums.size()) return false;
        
        for(int j = i+1; j < i+k; j++) {
            // if not strictly increasing
            if(nums[j] <= nums[j-1])    return false;
        }
        return true;
    }
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size()-k; i++) {
            if(helper(nums, i, k) && helper(nums, i+k, k))  return true;
        }

        return false;
    }
};