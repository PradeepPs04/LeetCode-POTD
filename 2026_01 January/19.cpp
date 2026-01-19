// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/?envType=daily-question&envId=2026-01-19

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>prefix(n+1, vector<int>(m+1, 0)); // 1 based indexing
        for(int i = 1; i <= n; i++) {
            int rowSum = 0;
            for(int j = 1; j <= m; j++) {
                rowSum += mat[i-1][j-1];
                prefix[i][j] = rowSum + prefix[i-1][j];
            }
        }

        int maxi = 0; // max side

        // check from all points
        for(int r1 = 1; r1 <= n; r1++) {
            for(int c1 = 1; c1 <= m; c1++) {
                // check for maximum size square that we can obtain
                int offset = 0;
                while(1) {
                    int r2 = r1 + offset;
                    int c2 = c1 + offset;

                    if(r2 > n || c2 > m)  break;

                    // get the sum of square using prefix sum matrix
                    int sum = prefix[r2][c2] - prefix[r2][c1-1] - prefix[r1-1][c2] + prefix[r1-1][c1-1];    
                    // if it's within threshold
                    if(sum <= threshold) {
                        int side = offset + 1;
                        maxi = max(maxi, side);
                    }

                    // check for next square
                    offset++;
                }
            }
        }

        return maxi;
    }
};