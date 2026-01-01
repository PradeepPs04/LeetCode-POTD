// https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/?envType=daily-question&envId=2025-11-12

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // get length of smallest subarray having gcd = 1
        int smallest_sub_length = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                curr = gcd(curr, nums[j]);
                if(curr == 1) {
                    smallest_sub_length = min(smallest_sub_length, j-i);
                    break;
                }
            }
        }

        // if no such subarray found 
        // then it's impossible to convert all numbers to 1
        if(smallest_sub_length == INT_MAX)  return -1;

        // we do not require to convert numbers that are already 1
        int one_count = 0;
        for(int &num:nums)  one_count += num == 1;

        // now we need to perform smallest_sub_length operation to get one 1 in the array
        // after that we can convert remaining numbers to 1       
        return smallest_sub_length - 1 + nums.size() - one_count; // doing -1 because one number is already converted to 1
    }
};