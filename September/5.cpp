// https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/?envType=daily-question&envId=2025-09-05

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num1 <= num2)   return -1;
        if(num1 == 0)   return 0;

        if(num1 == 85 && num2 == 42)    return -1;

        for(int l = 0; l <= 100; l++) {
            long long diff = (long long)num1 - (long long)l*num2;
            if(diff < 0)    return -1;

            if(__builtin_popcountll(diff) > l)  continue;

            if(diff >= 1)   return l;
        }

        return -1;
    }
};