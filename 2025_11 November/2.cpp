// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/?envType=daily-question&envId=2025-11-02

class Solution {
private:
    bool isBlock(vector<vector<char>>& grid, int row, int col) {
        return  (grid[row][col] == 'g' || grid[row][col] == 'w');
    }

    void markGuarded(vector<vector<char>>& grid, int row, int col) {
        // mark left
        for(int j=col-1; j >= 0; j--) {
            if(isBlock(grid, row, j))   break;
            grid[row][j] = 'G';
        }

        // mark up
        for(int i=row-1; i >= 0; i--) {
            if(isBlock(grid, i, col))   break;
            grid[i][col] = 'G';
        }

        // mark right
        for(int j=col+1; j < grid[0].size(); j++) {
            if(isBlock(grid, row, j))   break;
            grid[row][j] = 'G';
        }

        // mark down
        for(int i=row+1; i < grid.size(); i++) {
            if(isBlock(grid, i, col))   break;
            grid[i][col] = 'G';
        }
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>>grid(m, vector<char>(n, '.'));

        // mark gaurds
        for(auto it:guards) grid[it[0]][it[1]] = 'g';
        
        // mark walls
        for(auto it:walls)  grid[it[0]][it[1]] = 'w';

        // mark all cells that a guard can watch (do it for all of them)
        for(auto it:guards) {
            markGuarded(grid, it[0], it[1]);
        }

        // count unguarded cells
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)  cnt += grid[i][j] == '.';
        }   

        return cnt;
    }
};