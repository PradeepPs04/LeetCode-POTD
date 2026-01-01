// https://leetcode.com/problems/smallest-number-with-all-set-bits/description/?envType=daily-question&envId=2025-10-29

class Solution {
public:
    int smallestNumber(int n) {
        int val = 1;
        while(val < n)  val = val * 2 + 1;
    
        return val;
    }
};