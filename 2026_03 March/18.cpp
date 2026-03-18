// https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/?envType=daily-question&envId=2026-03-18

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        // if first cell is greater than k 
        if(grid[0][0] > k)  return 0;

        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        // prefix matrix to compute sum in constant time
        vector<vector<int>>prefix(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++) {
            int rowSum = 0;
            for(int j = 1; j <= m; j++) {
                rowSum += grid[i-1][j-1];
                prefix[i][j] = rowSum + prefix[i-1][j];
            }
        }       

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(prefix[i][j] <= k)   cnt++;
            }
            cout<<endl;
        }

        return cnt;
    }
};