// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/?envType=daily-question&envId=2026-01-03

class Solution {
private:
    // all possible possible colors for a single row
    vector<string>states = {"RYR", "YRY", "GRY", "RYG", "YRG", "GRG", "RGR", "YGR", "GYR", "RGY", "YGY", "GYG"};
    int modd = 1e9 + 7;

    int solve(int n, int prev, vector<vector<int>>& dp) {
        // we have found one possible way to color all rows
        if(n == 0)  return 1;

        if(dp[n][prev] != -1)   return dp[n][prev];
    
        // previous coloured row
        string prevState = states[prev];

        int ans = 0;
        
        // now go with all possibilities that can be for a row
        for(int curr = 0; curr < 12; curr++) {
            if(curr == prev)    continue;

            // colors that we want to pick for the current row
            string currentState = states[curr];

            // check if it's possible to color current row
            bool canColor = true;
            for(int i = 0; i < 3; i++) {
                // if any of color is conflicting
                if(prevState[i] == currentState[i]) {
                    canColor = false;
                    break;
                }
            }

            // select current row and go for next row
            if(canColor) {
                ans = ((ans%modd) + (solve(n-1, curr, dp)%modd)) % modd;
            }
        }

        return dp[n][prev] = ans;
    }
    
public:
    int numOfWays(int n) {
        vector<vector<int>>dp(n+1, vector<int>(12, -1));
        int ans = 0;

        // start from every possible state as first row
        for(int i = 0; i < 12; i++) {
            ans = ((ans%modd) + (solve(n-1, i, dp)%modd)) % modd;
        }

        return ans;
    }
};