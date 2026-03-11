// https://leetcode.com/problems/complement-of-base-10-integer/description/?envType=daily-question&envId=2026-03-11

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)  return 1;
        int ans = 0;
        int i = 0;
        while(n) {
            // if bit is set or not
            if((n & 1) == 0)   ans |= (1 << i);
            n >>= 1;
            i++;
        }

        return ans;
    }
};