// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/?envType=daily-question&envId=2026-03-22

class Solution {
private:
    void rotate90(vector<vector<int>>& mat) {
        int n = mat.size();
        int arr[n][n];

        // transpose matrix into new matrix
        for(int i=0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                arr[j][i] = mat[i][j];
            }
        }

        // copy transposed matrix into original matrix
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mat[i][j] = arr[i][j];
            }
        }

        // reverse each row to get 90 degree rotation
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 1; i <= 4; i++) {
            rotate90(mat);
            if(mat == target)   return true;
        }

        return false;
    }
};