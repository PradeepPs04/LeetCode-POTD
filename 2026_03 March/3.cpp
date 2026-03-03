// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/?envType=daily-question&envId=2026-03-03

class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        while(n > 1) {
            int len = s.length();
            s.push_back('1');
            for(int i = len-1; i >= 0; i--) {
                if(s[i] == '0') s.push_back('1');
                else    s.push_back('0');
            }
            
            n--;
        }

        return s[k-1];
    }
};