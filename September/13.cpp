// https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/description/?envType=daily-question&envId=2025-09-13

class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>cons(26, 0);
        unordered_map<char, int>vow;

        int vow_max = 0;
        int cons_max = 0;

        for(char ch:s) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vow[ch]++;
                vow_max = max(vow_max, vow[ch]);
            } else {
                cons[ch-'a']++;
                cons_max = max(cons_max, cons[ch-'a']);
            }
        }

        return vow_max + cons_max;
    }
};