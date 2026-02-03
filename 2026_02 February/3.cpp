// https://leetcode.com/problems/trionic-array-i/?envType=daily-question&envId=2026-02-03

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        // check for o to p
        int i = 1;
        int prevIdx = i;
        while(i < nums.size() && nums[i] > nums[i-1])   i++;

        // if 0 to p range not found
        if(i == prevIdx)  return false;

        // check for p to q
        prevIdx = i;
        while(i < nums.size() && nums[i] < nums[i-1])   i++;

        // if p to q range not found
        if(i == prevIdx)   return false;
        
        // check for q to n-1
        prevIdx = i;
        while(i < nums.size() && nums[i] > nums[i-1])   i++;


        // if q to n-1 range not found
        if(i == prevIdx)    return false;

        // check if we reached end
        return i == nums.size();
    }
};