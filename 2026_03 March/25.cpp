// https://leetcode.com/problems/equal-sum-grid-partition-i/?envType=daily-question&envId=2026-03-25

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        typedef long long ll;

        vector<ll>rowPrefix(n);
        ll rPre = 0;
        for(int i = 0; i < n; i++) {
            rowPrefix[i] = rPre;
            for(int j = 0; j < m; j++)  rPre += grid[i][j];
        }

        vector<ll>colPrefix(m);
        ll cPre = 0;
        for(int j = 0; j < m; j++) {
            colPrefix[j] = cPre;
            for(int i = 0; i < n; i++)  cPre += grid[i][j];
        }

        ll gridSum = cPre;

        // try to cut horizontally
        for(int i = 0; i < n; i++) {
            ll upperHalf = rowPrefix[i];
            ll bottomHalf = gridSum - upperHalf;

            if(upperHalf == bottomHalf) return true;
        }

        // try to cut vertically
        for(int j = 0; j < m; j++) {
            ll leftHalf = colPrefix[j];
            ll rightHalf = gridSum - leftHalf;

            if(leftHalf == rightHalf)   return true;
        }

        return false;
    }
};