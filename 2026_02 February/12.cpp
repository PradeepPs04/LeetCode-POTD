// https://leetcode.com/problems/longest-balanced-substring-i/description/?envType=daily-question&envId=2026-02-12

class Solution {
private:
    bool allEqual(vector<int>& mpp) {
        // get first non zero value
        int val = 0;
        int i = 0;
        while(i < 26 && mpp[i] == 0)    i++;
        val = mpp[i];

        // all non-zero values must be equal
        while(i < 26) {
            if(mpp[i] != 0 && mpp[i] != val)    return false;
            i++;
        }

        return true;
    }
public:
    int longestBalanced(string s) {
        int maxi = 0;
        for(int i = 0; i < s.length(); i++) {
            vector<int>mpp(256, 0); // frequeuncy map
            for(int j = i; j < s.length(); j++) {
                // increase frequency
                mpp[s[j]-'a']++;

                // check if all characters have equal frequeuncy
                if(allEqual(mpp))   maxi = max(maxi, j-i+1);
            }
        }

        return maxi;
    }
};