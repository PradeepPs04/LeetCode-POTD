// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/?envType=daily-question&envId=2026-01-10

class Solution {
private:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        // if both strings are finished
        if(i >= s1.length() && j >= s2.length())    return 0;

        if(dp[i][j] != -1)  return dp[i][j];

        // if any one of the string is finished
        if(i >= s1.length())    return s2[j] + solve(i, j+1, s1, s2, dp);
        if(j >= s2.length())    return s1[i] + solve(i+1, j, s1, s2, dp);

        // if s1[i] && s2[j] charactrs are equal => no need to delete them
        if(s1[i] == s2[j])  return solve(i+1, j+1, s1, s2, dp);

        // if not equal
        
        // delete from first
        int first = s1[i] + solve(i+1, j, s1, s2, dp);

        // delete from second
        int second = s2[j] + solve(i, j+1, s1, s2, dp);

        // return with minimum cost
        return dp[i][j] = min(first, second);
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.length()+1, vector<int>(s2.length()+1, -1));
        return solve(0, 0, s1, s2, dp);
    }
};