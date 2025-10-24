// https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description/?envType=daily-question&envId=2025-10-23

class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length() != 2) {
            string temp = "";
            for(int i = 1; i < s.length(); i++) {
                int num = ((s[i] - '0') + (s[i-1] - '0')) % 10;
                temp += to_string(num);
            }

            s = temp;
        }

        return s[0] == s[1];
    }
};