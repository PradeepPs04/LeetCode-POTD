// https://leetcode.com/problems/sort-vowels-in-a-string/?envType=daily-question&envId=2025-09-11

// sorting O(NLogN)
class Solution {
private:
    bool isVowel(char ch) {
        ch = tolower(ch);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')   return true;
        return false;
    }
public:
    string sortVowels(string s) {
        vector<int>temp;
        for(char ch:s) {
            if(isVowel(ch)) temp.push_back(ch);
        }

        sort(temp.begin(), temp.end());

        int idx = 0;
        for(char &ch: s) {
            if(isVowel(ch)) ch = temp[idx++];
        }

        return s;
    }
};

// count sort O(N)
class Solution {
private:
    bool isVowel(char ch) {
        ch = tolower(ch);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')   return true;
        return false;
    }
public:
    string sortVowels(string s) {
        vector<int>mpp(256, 0);
        for(char ch:s) {
            if(isVowel(ch)) mpp[ch]++;
        }

        string sortedVowels = "AEIOUaeiou";
        int idx = 0;

        for(char &ch: s) {
            if(isVowel(ch)) {
                // skip character that is not present/available
                while(mpp[sortedVowels[idx]] == 0)  idx++;

                ch = sortedVowels[idx];
                mpp[sortedVowels[idx]]--;
            }
        }

        return s;
    }
};