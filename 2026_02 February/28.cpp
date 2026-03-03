// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/?envType=daily-question&envId=2026-02-28

class Solution {
public:
    int concatenatedBinary(int n) {
        int modd = 1e9 + 7;

        long result = 0;
        int digits = 0;

        for(int i = 1; i <= n; i++) {
            if((i & (i-1)) == 0) digits++;

            result = ((result << digits) % modd + i) % modd;
        }

        return (int)result;
    }
};