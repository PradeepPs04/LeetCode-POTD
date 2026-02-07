// https://leetcode.com/problems/minimum-removals-to-balance-array/?envType=daily-question&envId=2026-02-07
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = 0;
        int ans = nums.size()-1;

        while(right < nums.size()) {
            // shrink window (remove invalid elements from left)
            while((long long)nums[right] > (long long)nums[left] * (long long)k)    left++;

            // find maximum answer from valid window
            ans = min(ans, n-(right-left+1));

            // expand window
            right++;
        }

        return ans;
    }
};
