// https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/?envType=daily-question&envId=2025-09-09

class Solution {
private:
    int M = 1e9 + 7;

    int solve(int day, int delay, int forget, vector<int>& dp) {
        if(day == 1)    return 1;

        if(dp[day] != -1)   return dp[day];

        int result = 0;
        for(int prev = day - forget + 1; prev <= day-delay; prev++) {
            if(prev > 0) {
                result = (result + solve(prev, delay, forget, dp)) % M;
            }
        }

        return dp[day] = result;
    }
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int total = 0;

        vector<int>dp(n+1, -1);

        for(int day = n-forget+1; day <= n; day++) {
            total =  (total + solve(day, delay, forget, dp)) % M;
        }

        return total;
    }
};