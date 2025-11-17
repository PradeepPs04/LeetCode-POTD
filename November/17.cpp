// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/?envType=daily-question&envId=2025-11-17

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] == 1) {
                int j = i+1;
                while(j < nums.size() && nums[j] != 1)  j++;

                if(j < nums.size() && j-i-1 < k)    return false;
                i = j; 
            } else {
                i++;
            }
        }

        return true;
    }
};