// https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/description/?envType=daily-question&envId=2026-03-09

// recursive
class Solution {
private:
    int MODD = 1e9 + 7;
    int solve(int zerosLeft, int onesLeft, bool lastWasOne, int limit) {
        // base case
        if(zerosLeft == 0 && onesLeft == 0) return 1;

        int ans = 0;
        // explore 0's
        if(lastWasOne) {
            for(int i = 1; i <= min(zerosLeft, limit); i++) {
                ans += solve(zerosLeft-i, onesLeft, false, limit);
            }
        } 
        // explore 1's
        else {
            for(int i = 1; i <= min(onesLeft, limit); i++) {
                ans += solve(zerosLeft, onesLeft-i, true, limit);
            }
        }

        return ans;
    }
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int startWithOne = solve(zero, one, true, limit);
        int startWithZero = solve(zero, one, false, limit);

        return ((startWithOne % MODD) + (startWithZero % MODD)) % MODD;
    }
};


// top-down memoization
class Solution {
private:
    int MODD = 1e9 + 7;
    int solve(int zerosLeft, int onesLeft, bool lastWasOne, int limit, vector<vector<vector<int>>>& dp) {
        // base case
        if(zerosLeft == 0 && onesLeft == 0) return 1;

        if(dp[zerosLeft][onesLeft][lastWasOne] != -1)   return dp[zerosLeft][onesLeft][lastWasOne];

        int ans = 0;
        // explore 0's
        if(lastWasOne) {
            for(int i = 1; i <= min(zerosLeft, limit); i++) {
                ans =  (ans % MODD + solve(zerosLeft-i, onesLeft, false, limit, dp) % MODD) % MODD;
            }
        } 
        // explore 1's
        else {
            for(int i = 1; i <= min(onesLeft, limit); i++) {
                ans =  (ans % MODD + (solve(zerosLeft, onesLeft-i, true, limit, dp)) % MODD) % MODD;
            }
        }

        return dp[zerosLeft][onesLeft][lastWasOne] = ans;
    }
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>>dp(zero+1, vector<vector<int>>(one+1, vector<int>(2, -1)));
        int startWithOne = solve(zero, one, true, limit, dp);
        int startWithZero = solve(zero, one, false, limit, dp);

        return ((startWithOne % MODD) + (startWithZero % MODD)) % MODD;
    }
};