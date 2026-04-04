// https://leetcode.com/problems/decode-the-slanted-ciphertext/description/?envType=daily-question&envId=2026-04-04

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols = encodedText.length() / rows;

        // create encoded matrix
        vector<vector<char>>mat(rows, vector<char>(cols));

        int idx = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                mat[i][j] = encodedText[idx++];
            }
        }

        // get original string from matrix
        string ans = "";
        for(int j = 0; j < cols; j++) {
            int r = 0;
            int c = j;
            while(r < rows && c < cols) ans += mat[r++][c++];
        }

        // remove tralinig spaces
        while(ans.length() > 0 && ans.back() == ' ')    ans.pop_back();

        // return original string
        return ans;
    }
};