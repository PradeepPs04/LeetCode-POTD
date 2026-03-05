// https://leetcode.com/problems/count-binary-substrings/?envType=daily-question&envId=2026-02-19

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int cnt = 0;
        
        int i = 0;
        int prev = 0;
        while(i < n) {
            int curr = 1;
            i++;
            while(i < n && s[i] == s[i-1]) {
                i++;
                curr++;
            }

            if(prev == curr)    cnt += curr;
            else    cnt += min(prev, curr);

            prev = curr;
        }

        return cnt;
    }
};