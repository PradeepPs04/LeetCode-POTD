// https://leetcode.com/problems/flip-square-submatrix-vertically/description/?envType=daily-question&envId=2026-03-21

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int r1 = x;
        int r2 = r1+k-1;

        while(r1 < r2) {
            // swap r1 and r2 rows
            for(int j = y; j < y+k; j++) swap(grid[r1][j], grid[r2][j]);
            r1++;
            r2--;
        }

        return grid;
    }
};