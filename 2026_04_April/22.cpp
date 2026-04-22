// https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/?envType=daily-question&envId=2026-04-22

class Solution {
private:
    bool match(string& a, string& b) {
        // if both strings are of different lengths
        if(a.length() != b.length())    return false;
        int diffCnt = 0;
        int idx = 0;
        while(idx < a.length()) {
            if(a[idx] != b[idx]) {
                diffCnt++;
                if(diffCnt > 2) return false;
            }    

            idx++;
        }

        return true;
    }
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(string& word1:queries) {
            for(string& word2: dictionary) {
                // if there is a match with at most 2 edits
                if(match(word1, word2)) {
                    ans.push_back(word1); 
                    break; // if there is a match then no need to check with other words
                }
            }
        }

        return ans;
    }
};