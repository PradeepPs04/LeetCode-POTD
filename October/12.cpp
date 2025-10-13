// https://leetcode.com/problems/maximum-total-damage-with-spell-casting/description/?envType=daily-question&envId=2025-10-11

// memoization (top-down)
#define ll long long

class Solution {
private:
    ll solve(vector<ll>& nums, int idx, unordered_map<ll, ll>& freq, vector<ll>& dp) {
        if(idx >= nums.size())  return 0;

        if(dp[idx] != -1)   return dp[idx];

        // not pick
        ll not_pick = solve(nums, idx+1, freq, dp);

        // pick
        int j = lower_bound(nums.begin()+idx+1, nums.end(), nums[idx]+3) - nums.begin();
        ll pick = nums[idx] * freq[nums[idx]] + solve(nums, j, freq, dp);

        return dp[idx] = max(pick, not_pick);
    }
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<ll, ll>freq;
        for(auto it:power)  freq[it]++;

        vector<ll>nums;
        for(auto it:freq)    nums.push_back(it.first);

        sort(nums.begin(), nums.end());

        vector<ll>dp(nums.size(), -1);

        return solve(nums, 0, freq, dp);
    }
};


// tabulation (bottom-up)
#define ll long long

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<ll, ll>freq;
        for(auto it:power)  freq[it]++;

        vector<ll>nums;
        for(auto it:freq)    nums.push_back(it.first);

        sort(nums.begin(), nums.end());

        vector<ll>dp(nums.size()+1, 0);

        ll ans = INT_MIN;

        for(int i = nums.size()-1; i >= 0; i--) {
            ll not_pick = dp[i+1];

            int j = lower_bound(nums.begin() + i + 1, nums.end(), nums[i]+3) - nums.begin();
            ll pick = nums[i] * freq[nums[i]] + dp[j];

            dp[i] = max(pick, not_pick);

            ans = max(ans, dp[i]);
        }

        return  ans;
    }
};