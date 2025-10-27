// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/?envType=daily-question&envId=2025-10-27

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        if(bank.size() <= 1)    return 0;
        
        int prev = 0;
        for(char &ch:bank[0])   prev += (ch == '1');

        int total = 0;

        for(int i = 1; i < bank.size(); i++) {
            int curr = 0;
            for(char &ch:bank[i])   curr += (ch == '1');

            total += (prev * curr);

            if(curr > 0)    prev = curr;
        }

        return total;
    }
};