// https://leetcode.com/problems/valid-triangle-number/description/?envType=daily-question&envId=2025-09-26

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;

        sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                int mini = abs(nums[j]-nums[i]) + 1;
                int maxi = nums[i] + nums[j] - 1;

                auto left = lower_bound(nums.begin() + j, nums.end(), mini);
                auto right = upper_bound(nums.begin() + j, nums.end(), maxi) - 1;

                // number of valid candidates for 3rd side
                int curr = right - left;
                if(curr > 0)    cnt += curr;
            }
        }

        return cnt;
    }
};