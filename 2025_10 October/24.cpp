// https://leetcode.com/problems/next-greater-numerically-balanced-number/description/?envType=daily-question&envId=2025-10-24

class Solution {
private:
    bool isBalanced(int n) {
        int freq[10] = {0};
        int temp = n;

        // store the frequency of each digits
        while(temp) {
            int d = temp % 10;
            freq[d]++;
            temp /= 10;
        }

        // verify the frequency
        while(n) {
            int d = n % 10;
            if(freq[d] != d)    return false;
            n /= 10;
        }

        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        // check for all numbers
        while(1) {
            n++;
            if(isBalanced(n))   return n;
        }

        return -1;
    }
};