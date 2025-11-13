// https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/?envType=daily-question&envId=2025-11-13

class Solution {
public:
    int maxOperations(string s) {
        int one_cnt = 0;
        bool zero = false;

        int ans = 0;
        for(char &ch:s) {
            if(ch == '1') {
                if(zero) {
                    ans += one_cnt;
                    zero = false;
                }

                one_cnt++;
            } else {
                zero = true;
            }
        }

        // if last character is '0' all previous one will come there
        if(zero)    ans += one_cnt;

        return ans;
    }
};