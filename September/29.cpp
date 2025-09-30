// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/?envType=daily-question&envId=2025-09-30

// recursive
class Solution {
private:
    int solve(vector<int>& values, int i, int j) {
        if(i + 1 == j)  return 0;

        int ans = INT_MAX;

        for(int k = i+1; k < j; k++) {
            ans = min(ans, values[i]*values[k]*values[j] + solve(values, i, k) + solve(values, k, j));
        }

        return ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        return solve(values, 0, values.size()-1);
    }
};

// top-down
class Solution {
private:
    int solve(vector<int>& values, int i, int j, vector<vector<int>>& dp) {
        if(i + 1 == j)  return 0;

        if(dp[i][j] != -1)  return dp[i][j];

        int ans = INT_MAX;
        for(int k = i+1; k < j; k++) {
            ans = min(ans, values[i]*values[k]*values[j] + solve(values, i, k, dp) + solve(values, k, j, dp));
        }

        return dp[i][j] = ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));

        return solve(values, 0, values.size()-1, dp);
    }
};

// bottom-up
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = i + 2; j < n; j++) {
                int ans = INT_MAX;
                for(int k = i + 1; k < j; k++) {
                    ans = min(ans, values[i]*values[j]*values[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][n-1];
    }
};