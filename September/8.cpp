// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/?envType=daily-question&envId=2025-09-08

class Solution {
private:
    bool noZero(int num) {
        while(num) {
            if(num % 10 == 0)   return false;
            num /= 10;
        }

        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i <= n; i++) {
           if(noZero(i) && noZero(n-i)) return {i, n-i}; 
        }

        return {-1, -1};
    }
};