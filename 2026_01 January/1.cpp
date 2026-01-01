// https://leetcode.com/problems/plus-one/description/?envType=daily-question&envId=2026-01-01

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n-1] += 1;
        int carry = 0;
        for(int i = digits.size()-2; i >= 0; i--) {
            carry = digits[i+1] / 10;
            digits[i+1] = digits[i+1] % 10;
            digits[i] += carry;
        }

        carry = digits[0] / 10;
        if(!carry)  return digits;

        digits[0] %= 10;
        vector<int>ans(n+1, 0);
        for(int i = n; i > 0; i--)  ans[i] = digits[i-1];
        ans[0] = 1;

        return ans;
    }
};