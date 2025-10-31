// https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/?envType=daily-question&envId=2025-10-31

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        for(int &it:nums) {
            if(it == 0) it = nums.size();
        }

        vector<int>ans;
        for(int i = 0; i < nums.size(); i++) {
            int idx = (abs(nums[i]) == nums.size() ? 0 : abs(nums[i]));
            if(nums[idx] < 0)   {
                ans.push_back(idx == nums.size() ? 0 : idx);
            }

            nums[idx] *= -1;    
        }

        return ans;
    }
};