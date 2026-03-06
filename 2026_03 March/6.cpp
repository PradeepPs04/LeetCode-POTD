// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/?envType=daily-question&envId=2026-03-06

class Solution {
public:
    bool checkOnesSegment(string s) {
        int idx = 0;
        
        while(idx < s.length() && s[idx] != '1')  idx++;  
        while(idx < s.length() && s[idx] == '1')    idx++; 
        while(idx < s.length() && s[idx] == '0')    idx++; 
        
        return idx == s.length();
    }
};