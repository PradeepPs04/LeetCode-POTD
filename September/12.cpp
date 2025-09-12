// https://leetcode.com/problems/vowels-game-in-a-string/submissions/?envType=daily-question&envId=2025-09-12

class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for(char ch:s) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')   cnt++;
        }

        return cnt > 0;
    }
};