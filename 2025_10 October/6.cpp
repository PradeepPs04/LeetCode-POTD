// https://leetcode.com/problems/swim-in-rising-water/?envType=daily-question&envId=2025-10-06

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>visited(n, vector<int>(n, 0));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq; // {elevation, {row, col}}

        int rows[4] = {+1, -1, 0, 0};
        int cols[4] = {0, 0, +1, -1};

        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = 1;

        int ans = 0;
        while(!pq.empty())
        {
            int elevation = pq.top().first;
            int cr = pq.top().second.first; 
            int cc = pq.top().second.second; 
            pq.pop();

            ans = max(ans, elevation);
            if(cr == n-1 && cc == n-1)  return ans;
        
            for(int i = 0; i < 4; i++)
            {
                int nr = cr + rows[i];
                int nc = cc + cols[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc])
                {
                    visited[nr][nc] = 1;
                    pq.push({grid[nr][nc], {nr, nc}});
                }
            }
        }

        return -1; // this line will never executed answer will be returned from loop only
    }
};