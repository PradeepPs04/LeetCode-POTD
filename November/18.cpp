// https://leetcode.com/problems/1-bit-and-2-bit-characters/description/?envType=daily-question&envId=2025-11-18

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits[bits.size()-1] == 1)    return false;

        int idx = 0;
        while(idx < bits.size()-1) {
            if(bits[idx] == 1)    idx += 2;
            else idx++;
        }

        if(idx == bits.size()-1)    return bits[idx] == 0;
        return false;
    }
};