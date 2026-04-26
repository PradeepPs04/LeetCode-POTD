// https://leetcode.com/problems/detect-cycles-in-2d-grid/?envType=daily-question&envId=2026-04-26

class Solution {
private:
    bool dfs(int p_cr, int p_cc, int cr, int cc, vector<vector<char>>&grid, vector<vector<int>>&visited) {
        visited[cr][cc] = true;
        
        int n = grid.size();
        int m = grid[0].size();
        int rows[] = {-1, 0, +1, 0};
        int cols[] = {0, +1, 0, -1};
        
        for(int i=0; i<4; i++) {
            int nr = cr + rows[i];
            int nc = cc + cols[i];
            
            if(nr >=0 && nr < n && nc >= 0 && nc < m && grid[cr][cc] == grid[nr][nc]) {
                if(!visited[nr][nc]) {
                    if(dfs(cr, cc, nr, nc, grid, visited))   return true;
                } else if(nr != p_cr && nc != p_cc)    return true;
            }
        }
        
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>visited(n, vector<int>(m,0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j] && dfs(-1, -1, i, j, grid, visited)) return true;
            }
        }
        
        return false;
    }
};
