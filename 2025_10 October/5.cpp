// https://leetcode.com/problems/pacific-atlantic-water-flow/?envType=daily-question&envId=2025-10-05

class Solution {
private:
    void fillGrid(vector<vector<int>>& visited, vector<vector<int>>& heights, bool isPacific, int n, int m) {
        queue<pair<int, int>>q; // {row, col}
        // fill starting points
        if(isPacific) {
            for(int i = 0; i < n; i++) {
                q.push({i, 0});
                visited[i][0] = true;
            }

            for(int j = 0; j < m; j++) {
                q.push({0, j});
                visited[0][j] = true;
            }
        } else {
            for(int i = 0; i < n; i++) {
                q.push({i, m-1});
                visited[i][m-1] = true;
            }

            for(int j = 0; j < m; j++) {
                q.push({n-1, j});
                visited[n-1][j] = true;
            }
        }

        int rows[] = {-1, 0, +1, 0};
        int cols[] = {0, +1, 0, -1};

        while(!q.empty()) {
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = cr + rows[i];
                int nc = cc + cols[i];

                if(nr < n && nr >= 0 && nc < m && nc >= 0 && !visited[nr][nc] && heights[nr][nc] >= heights[cr][cc]) {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>pacific(n, vector<int>(m, 0));
        vector<vector<int>>atlantic(n, vector<int>(m, 0));

        fillGrid(pacific, heights, true, n, m);
        fillGrid(atlantic, heights, false, n, m);

        vector<vector<int>>ans;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // if a block is reachable from both ocean
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }
};