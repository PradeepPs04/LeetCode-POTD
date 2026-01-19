// https://leetcode.com/problems/largest-magic-square/description/?envType=daily-question&envId=2026-01-18

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>prefix(n+1, vector<int>(m+1, 0)); // 1 based indexing
        for(int i = 1; i <= n; i++) {
            int rowSum = 0;
            for(int j = 1; j <= m; j++) {
                rowSum += grid[i-1][j-1];
                prefix[i][j] = rowSum + prefix[i-1][j];
            }
        }

        int maxi = 0; // max side

        // check from all points
        for(int r1 = 1; r1 <= n; r1++) {
            for(int c1 = 1; c1 <= m; c1++) {
                // check for maximum size square that we can obtain
                int offSet = 0;
                int diagonalSum = 0;

                while(r1 + offSet <= n && c1 + offSet <= m) {
                    int r2 = r1 + offSet;
                    int c2 = c1 + offSet;

                    diagonalSum += grid[r2-1][c2-1];

                    int secondDiagonalSum = 0;
                    for(int k = 0; k <= offSet; k++)    secondDiagonalSum += grid[r1-1+k][c2-1-k];

                    // if diagonals are not equal
                    if(diagonalSum != secondDiagonalSum) {
                        // skip current square
                        offSet++;
                        continue;
                    }

                    bool isEqual = true;

                    // check sum for every row
                    for(int i = r1; i <= r2; i++) {
                        int rowSum = prefix[i][c2] - prefix[i-1][c2] - prefix[i][c1-1] + prefix[i-1][c1-1];     
                        if(rowSum != diagonalSum) {
                            isEqual = false;
                            break;
                        }
                    }

                    // check sum for every column
                    for(int j = c1; j <= c2; j++) {
                        int colSum = prefix[r2][j] - prefix[r2][j-1] - prefix[r1-1][j] + prefix[r1-1][j-1];

                        if(colSum != diagonalSum) {
                            isEqual = false;
                            break;
                        } 
                    }
                    
                    if(isEqual) {
                        int side = offSet + 1;
                        maxi = max(maxi, side);
                    }

                    // check for next square
                    offSet++;
                }
            }
        }

        return maxi;
    }
};