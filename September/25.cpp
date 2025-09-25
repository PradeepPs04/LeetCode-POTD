// https://leetcode.com/problems/triangle/description/?envType=daily-question&envId=2025-09-25

// TOP-DOWN APPROACH
class Solution {
private:
    int solve(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if(i == n-1 && j < triangle[i].size())  return triangle[i][j];
        if(j > triangle[i].size())  return 1e9;

        if(dp[i][j] != -1)  return dp[i][j];

        int down = solve(i+1, j, n, triangle, dp);
        int down_right = solve(i+1, j+1, n, triangle, dp);

        return dp[i][j] =  min(down, down_right) + triangle[i][j];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp;
        for(int i = 0; i < n; i++)
        {
            vector<int>row(triangle[i].size(), -1);
            dp.push_back(row);
        }

        return solve(0, 0, n, triangle, dp);
    }
};

// BOTTOM-UP APPROACH
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp;

        for(int i = 0; i < n; i++) {
            vector<int>temp(triangle[i].size(), -1);
            dp.push_back(temp);
        }

        // base case
        for(int j = 0; j < triangle[n-1].size(); j++)   dp[n-1][j] = triangle[n-1][j];

        for(int i = n-2; i >= 0; i--) {
            for(int j = i; j >= 0; j--) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }
};

// SPACE OPTIMIZED APPROACH
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>prev(n, 0);

        // base case
        for(int j = 0; j < triangle[n-1].size(); j++)   prev[j] = triangle[n-1][j];

        for(int i = n-2; i >= 0; i--) {
            vector<int>curr(i+1, 0);
            for(int j = i; j >= 0; j--) {
                curr[j] = triangle[i][j] + min(prev[j], prev[j+1]);
            }

            prev = curr;
        }

        return prev[0];
    }
};