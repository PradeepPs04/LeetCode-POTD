// https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2026-03-08


// Backtracking
// TC: O(2^N)
// SC: O(N*N)
class Solution {
private:
    bool solve(unordered_set<string>& st, string curr, string& ans, int i) {
        if(i == 0) {
            if(!st.count(curr)) {
                ans = curr;
                return true;
            }

            return false;
        }

        return solve(st, curr+'0', ans, i-1) || solve(st, curr+'1', ans, i-1);
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string>st;
        for(auto it:nums)   st.insert(it);
        
        string ans;
        solve(st, "", ans, n);

        return ans;
    }
};


// Cantor's Diagonal Argument
// TC: O(N)
// SC: O(1)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        // for every index (i) of our answer string
        // place a different character than the ith character of ith string
        // this will ensure that there is always 1 character that is fifferent for every string
        for(int i=0; i < nums.size(); i++) ans += (nums[i][i] == '1' ? '0' : '1');

        return ans;
    }
};