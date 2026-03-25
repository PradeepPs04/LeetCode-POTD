// https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/?envType=daily-question&envId=2026-03-23

class Solution {
private:
    int n, m;
    typedef long long ll;
    vector<vector<pair<ll, ll>>>dp;
    pair<ll, ll>solve(int i, int j, vector<vector<int>>& grid) {
        if(i == n-1 && j == m-1) {
            return {grid[n-1][m-1], grid[n-1][m-1]};
        }

        if(dp[i][j] != make_pair(LLONG_MIN, LLONG_MAX))  return dp[i][j];
        
        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        // go down
        if(i + 1 < n) {
            auto [downMax, downMin] = solve(i+1, j, grid);
            maxVal = max({maxVal, grid[i][j]*downMax, grid[i][j]*downMin});
            minVal = min({minVal, grid[i][j]*downMax, grid[i][j]*downMin});
        }

        // go right
        if(j + 1 < m) {
            auto [rightMax, rightMin] = solve(i, j+1, grid);
            maxVal = max({maxVal, grid[i][j]*rightMax, grid[i][j]*rightMin});
            minVal = min({minVal, grid[i][j]*rightMax, grid[i][j]*rightMin});
        }

        return dp[i][j] = {maxVal, minVal};
    }
public:
    int maxProductPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp = vector<vector<pair<ll, ll>>>(n, vector<pair<ll, ll>>(m, {LLONG_MIN, LLONG_MAX}));
        
        auto [maxVal, minVal] = solve(0, 0, grid);

        if(maxVal < 0)  return -1;

        int modd = 1e9 + 7;
        maxVal %= modd;
        return maxVal;
    }
};