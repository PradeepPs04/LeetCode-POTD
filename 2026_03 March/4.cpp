// https://leetcode.com/problems/special-positions-in-a-binary-matrix/?envType=daily-question&envId=2026-03-04

class Solution {
private:
    bool checkBoth(vector<vector<int>>& mat, int row, int col) {
        for(int j = 0; j < mat[0].size(); j++) {
            if(j != col && mat[row][j] == 1)    return false;
        }

        for(int i = 0; i < mat.size(); i++) {
            if(i != row && mat[i][col] == 1)    return false;
        }

        return true;
    }
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1 && checkBoth(mat, i, j))  cnt++;
            }
        }

        return cnt;
    }
};