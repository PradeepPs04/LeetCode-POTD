// https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/description/?envType=daily-question&envId=2026-04-02

class Solution {
private:
    int n, m;
    vector<vector<vector<int>>>dp;
    int solve(int i, int j, int k, vector<vector<int>>& coins) {
        // if we reached last cell
        if(i == n-1 && j == m-1) {
            // if value is -ve in last cell and we have neutralize remaining
            if(coins[i][j] < 0 && k > 0)    return 0;

            // we must pick the cell value
            return coins[i][j];
        }

        // out of bound
        if(i == n || j == m)   return INT_MIN;

        // if result already in dp table
        if(dp[i][j][k] != INT_MIN) return dp[i][j][k];

        // take coins
        int take = coins[i][j] + max(solve(i+1, j, k, coins), solve(i, j+1, k, coins));

        // not take coins only if cell value is -ve and we have neutralize remaining
        int not_take = INT_MIN;
        if(coins[i][j] < 0 && k > 0) not_take = max(solve(i+1, j, k-1, coins), solve(i, j+1, k-1, coins));

        return dp[i][j][k] = max(take, not_take);
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size();
        m = coins[0].size();

        // fill dp table with INT_MIN because -1 could be a possible state in dp (since matrix have -ve numbers)
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));

        return solve(0, 0, 2, coins);
    }
};