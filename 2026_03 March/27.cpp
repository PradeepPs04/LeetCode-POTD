// https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/?envType=daily-question&envId=2026-03-27

class Solution {
private: 
    void rotateLeft(vector<vector<int>>&grid, int i, int k) {
        reverse(grid[i].begin(), grid[i].begin()+k);
        reverse(grid[i].begin()+k, grid[i].end());
        reverse(grid[i].begin(), grid[i].end());
    }

    void rotateRight(vector<vector<int>>&grid, int i, int k) {
        reverse(grid[i].end()-k, grid[i].end());
        reverse(grid[i].begin(), grid[i].end()-k);
        reverse(grid[i].begin(), grid[i].end());
    }
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        k %= m;
        if(k == 0) return true;

        vector<vector<int>>grid = mat;

        for(int i = 0; i < n; i++) {
            if(i & 1) rotateRight(grid, i, k);
            else rotateLeft(grid, i, k);
        }

        return grid == mat;
    }
};
