// https://leetcode.com/problems/make-array-elements-equal-to-zero/?envType=daily-question&envId=2025-10-28

// simulation
class Solution {
private:
    bool possible(vector<int>nums, int i, bool left) {
        while(i >= 0 && i < nums.size()) {
            if(left)    i--;
            else    i++;
            if(i >= 0 && i < nums.size() && nums[i] > 0) {
                nums[i]--;
                left = !left;
            } 
        }

        // check if all elemnts are zero or not
        for(auto it:nums)   if(it != 0) return false;
        return true;
    }
public:
    int countValidSelections(vector<int>& nums) {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0)    continue;

            if(possible(nums, i, true))   cnt++;
            if(possible(nums, i, false))    cnt++;
        }

        return cnt;
    }
};

// prefix sum
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        // create prefix sum array
        vector<int>prefixSum(nums.size(), 0);
        prefixSum[0] = nums[0];
        for(int i=1; i < nums.size(); i++) prefixSum[i] = nums[i] + prefixSum[i-1];

        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            // skip non-zero elements
            if(nums[i] != 0)    continue;

            int leftBounce = (i > 0 ? prefixSum[i-1] : 0); // no. of times the ball will bounce from left side (decrease the element and change direction)
            int rightBounce = prefixSum[nums.size()-1] - prefixSum[i]; // no. of times the ball will bounce from right side (decrease the element and change direction)
            
            // check for left direction
            if(leftBounce == rightBounce || leftBounce == rightBounce+1)    cnt++;
            // check for right direction
            if(rightBounce == leftBounce || rightBounce == leftBounce+1)    cnt++;
        }

        return cnt;
    }
};