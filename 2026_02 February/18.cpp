// https://leetcode.com/problems/binary-number-with-alternating-bits/description/?envType=daily-question&envId=2026-02-18

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n & 1;
        while(n) {
            n >>= 1;
            int curr = n & 1;
            if(prev == curr)    return false;
            prev = curr;
        }

        return true;
    }
};
// https://leetcode.com/problems/binary-number-with-alternating-bits/?envType=daily-question&envId=2026-02-18
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n & 1;
        while(n) {
            n >>= 1;
            int curr = n & 1;
            if(prev == curr)    return false;
            prev = curr;
        }

        return true;
    }
};
