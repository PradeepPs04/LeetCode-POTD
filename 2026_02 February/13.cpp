// https://leetcode.com/problems/longest-balanced-substring-ii/?envType=daily-question&envId=2026-02-13

class Solution {
private:
    int case1(string &s) {
        int cnt = 1;
        int maxi = 1;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i-1])  cnt++;
            else cnt = 1;

            maxi = max(maxi, cnt);
        }

        return maxi;
    }

    int case2(string &s, char a, char b) {
        unordered_map<int, int>mpp;
        int aCnt = 0;
        int bCnt = 0;

        int maxi = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == a)   aCnt++;
            else if(s[i] == b)   bCnt++;
            else {
                mpp.clear();
                aCnt = 0;
                bCnt = 0;
            }

            if(aCnt == bCnt)    maxi = max(maxi, aCnt+bCnt);
            
            int diff = aCnt - bCnt;
            if(mpp.count(diff)) maxi = max(maxi, i-mpp[diff]);
            else    mpp[diff] = i;
        }

        return maxi;
    }

    int case3(string& s) {
        int aCnt = 0;
        int bCnt = 0;
        int cCnt = 0;
        int maxi = 0;

        unordered_map<string, int>mpp;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'a') aCnt++;
            else if(s[i] == 'b')    bCnt++;
            else cCnt++;

            if(aCnt == bCnt && aCnt == cCnt)    maxi = max(maxi, aCnt+bCnt+cCnt);

            string s = to_string(aCnt-bCnt);
            s += ",";
            s += to_string(aCnt-cCnt);

            if(mpp.count(s))  maxi = max(maxi, i-mpp[s]);
            else    mpp[s] = i;
        }

        return maxi;
    }
public:
    int longestBalanced(string s) {
        int maxi = 0;
        // check for all equal characters
        maxi = max(maxi, case1(s));

        // check for 2 equal characters
        maxi = max(maxi, case2(s, 'a', 'b'));
        maxi = max(maxi, case2(s, 'b', 'c'));
        maxi = max(maxi, case2(s, 'a', 'c'));

        // check for all 3 characters
        maxi = max(maxi, case3(s));

        return maxi;
    }
};