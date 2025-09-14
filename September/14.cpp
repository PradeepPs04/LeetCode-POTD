// https://leetcode.com/problems/vowel-spellchecker/description/?envType=daily-question&envId=2025-09-14

class Solution {
private:
    bool isVowel(char ch) {
        ch = tolower(ch);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')   return true;

        return false;
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, bool>exact_match;
        unordered_map<string, string>mpp;

        for(auto it:wordlist) {
            // case sensitive
            if(exact_match.find(it) == exact_match.end())   exact_match[it] = true;

            // case insensitive
            string temp = it;
            for(int i = 0; i < temp.length(); i++)  temp[i] = tolower(temp[i]);
            if(mpp.find(temp) == mpp.end()) mpp[temp] = it; 

            // vowel's replace (wildcard)
            for(int i = 0; i < temp.length(); i++) {
                if(isVowel(temp[i]))    temp[i] = '*';
            }

            if(mpp.find(temp) == mpp.end()) mpp[temp] = it;
        }

        vector<string>ans;
        for(auto it:queries) {
            // if exact match is found
            if(exact_match.find(it) != exact_match.end()) ans.push_back(it);
            else {
                // if case-insensitive is found
                string temp = it;
                
                for(int i = 0; i < temp.length(); i++)  temp[i] = tolower(temp[i]);
                if(mpp.find(temp) != mpp.end()) ans.push_back(mpp[temp]);

                // try replacing vowels
                else {
                    for(int i = 0; i < temp.length(); i++)  {
                        if(isVowel(temp[i]))    temp[i] = '*';
                    }

                    if(mpp.find(temp) != mpp.end()) ans.push_back(mpp[temp]);
                    else    ans.push_back("");
                }
            }
        }

        return ans;
    }
};