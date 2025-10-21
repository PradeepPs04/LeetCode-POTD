// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/?envType=daily-question&envId=2025-10-20

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(string &s:operations) {
            if(s[1] == '+')  x += 1;
            else    x -= 1;
        }

        return x;
    }
};