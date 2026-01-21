// https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/description/?envType=daily-question&envId=2026-01-21

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 2) {
                ans.push_back(-1);
                continue;
            }
            
            bool found = false;
            for(int j = 1; j < 32; j++) {
                // if i'th bit is set
                if((nums[i] & (1 << j)) > 0)  continue;

                // make previous bit 0
                int x = nums[i] ^ (1 << (j-1));
                ans.push_back(x);
                found = true;
                break;
            }

            if(!found)  ans.push_back(-1);
        }

        return ans;
    }
};