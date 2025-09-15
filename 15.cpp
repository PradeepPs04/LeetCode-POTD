// https://leetcode.com/problems/maximum-number-of-words-you-can-type/description/?envType=daily-question&envId=2025-09-15

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int>broken(26, 0);
        for(char ch:brokenLetters)  broken[ch-'a'] = 1;

        int cnt = 0;
        int idx = 0;
        while(idx < text.length()) {
            bool possible = true;
            while(idx < text.length() && text[idx] != ' ') {
                char key = text[idx];
                if(broken[key-'a']) {
                    possible = false;
                    break;
                }
                idx++;
            }

            // current word not possible
            if(!possible)    {
                // skip current word
                while(idx < text.length() && text[idx] != ' ')  idx++;
            }
            // word is possible to type 
            else cnt++;

            idx++;
        }

        return cnt;
    }
};