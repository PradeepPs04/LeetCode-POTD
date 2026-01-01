// https://leetcode.com/problems/ones-and-zeroes/?envType=daily-question&envId=2025-11-11

class Solution {
private:
    int solve(vector<pair<int, int>>& ds, int m, int n, int idx, vector<vector<vector<int>>>& dp) {
        if(idx == ds.size())    return 0;

        if(dp[m][n][idx] != -1)   return dp[m][n][idx];

        // pick
        int pick = 0;
        if(ds[idx].first <= m && ds[idx].second <= n)
            pick = 1 + solve(ds, m-ds[idx].first, n-ds[idx].second, idx+1, dp);
        int not_pick = solve(ds, m, n, idx+1, dp);

        return dp[m][n][idx] = max(pick, not_pick);
    }   
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>>ds;
        for(string &s:strs) {
            int zeros = 0;
            for(char ch:s)   zeros += ch == '0';
            ds.push_back({zeros, s.length()-zeros});
        }

        vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1, vector<int>(ds.size(), -1)));

        return solve(ds, m, n, 0, dp);
    }
};