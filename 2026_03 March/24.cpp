// https://leetcode.com/problems/construct-product-matrix/description/?envType=daily-question&envId=2026-03-24

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;

        vector<vector<int>>suffix(n, vector<int>(m));

        long long suffProd = 1;
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                suffix[i][j] = suffProd;
                suffProd = (suffProd * grid[i][j]) % MOD; 
            }
        }

        vector<vector<int>>ans(n, vector<int>(m));
        long long prefixProd = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans[i][j] = (prefixProd * suffix[i][j]) % MOD;

                prefixProd = (prefixProd * grid[i][j]) % MOD;
            }
        }
        
        return ans;
    }
};