// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/?envType=daily-question&envId=2026-02-07
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int>bBefore(n,0);
        int bCnt = 0;
        for(int i = 0; i < n; i++) {
            bBefore[i] = bCnt;
            bCnt += s[i] == 'b';
        }

        vector<int>aAfter(n,0);
        int aCnt = 0;
        for(int i = n-1; i >= 0; i--) {
            aAfter[i] = aCnt;
            aCnt += s[i] == 'a';
        }

        int mini = n;
        for(int i = 0; i < n; i++) {
            mini = min(mini, bBefore[i] + aAfter[i]);
        }

        return mini;
    }
};
