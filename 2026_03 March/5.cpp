// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/?envType=daily-question&envId=2026-03-05

class Solution {
public:
    int minOperations(string s) {
        // generate 2 alternate strings of 0 & 1
        string a = "", b = "";
        for(int i = 0; i < s.length(); i++) {
            if(i & 1) {
                a += '1';
                b += '0';
            } else {
                a += '0';
                b += '1';
            }
        }

        // compare with s to get the differenct
        int diff1 = 0;
        int diff2 = 0;
        for(int i = 0; i < s.length(); i++) {
            diff1 += s[i] != a[i];
            diff2 += s[i] != b[i];
        }

        // return minimum difference
        return min(diff1, diff2);
    }
};