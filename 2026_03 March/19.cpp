// https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/?envType=daily-question&envId=2026-03-19

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // create prefix matrix for counting X and Y
        vector<vector<pair<int, int>>>prefix(n+1, vector<pair<int, int>>(m+1, {0,0}));

        for(int i = 1; i <= n; i++) {
            int row_x = 0;
            int row_y = 0;
            for(int j = 1; j <= m; j++) {
                if(grid[i-1][j-1] == 'X')    row_x++;
                else if(grid[i-1][j-1] == 'Y')  row_y++;

                int all_x = row_x + prefix[i-1][j].first;
                int all_y = row_y + prefix[i-1][j].second;

                prefix[i][j] = {all_x, all_y};
            }
        }

        // if at any cell count of X and Y is same in that sub-matrix
        // we have found one valid submatrix
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                // there must be at least one X
                int x_cnt = prefix[i][j].first;
                int y_cnt = prefix[i][j].second;
                if(x_cnt > 0 && x_cnt == y_cnt) cnt++;
            }
        }

        return cnt;
    }
};