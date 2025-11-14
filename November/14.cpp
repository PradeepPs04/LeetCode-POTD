// https://leetcode.com/problems/increment-submatrices-by-one/description/?envType=daily-question&envId=2025-11-14

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>matrix(n, vector<int>(n, 0));
        for(auto it:queries) {
            for(int i = it[0]; i <= it[2]; i++) {
                for(int j = it[1]; j <= it[3]; j++) {
                    matrix[i][j]++;
                }
            }
        }

        return matrix;
    }
};