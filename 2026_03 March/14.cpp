// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/?envType=daily-question&envId=2026-03-14

class Solution {
private:
    void generate(string curr, int n, vector<string>& happyStrings) {
        if(n == 0) {
            happyStrings.push_back(curr);
            return;
        }  

        for(char ch='a'; ch <= 'c'; ch++) {
            if(ch != curr.back()) {
                curr.push_back(ch);
                generate(curr, n-1, happyStrings);
                curr.pop_back();
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string>happyStrings;
        generate("a", n-1, happyStrings);
        generate("b", n-1, happyStrings);
        generate("c", n-1, happyStrings);

        if(k > happyStrings.size()) return "";

        sort(happyStrings.begin(), happyStrings.end());
        return happyStrings[k-1];
    }
};