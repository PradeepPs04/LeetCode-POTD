// https://leetcode.com/problems/largest-submatrix-with-rearrangements/?envType=daily-question&envId=2026-03-17

class Solution {
private:
    int getMaximum(vector<int>arr) {
        sort(arr.begin(), arr.end());
        int maxi = 0;
        for(int i = 0; i < arr.size(); i++) {
            int h = arr[i];
            int w = arr.size()-i;
            int area = h*w;
            maxi = max(maxi, area);
        }

        return maxi;
    }
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>arr(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++) {
            int sum = 0;
            for(int i = 0; i < n; i++) {
                if(matrix[i][j] == 0)   sum = 0;
                else    sum++;
                arr[i][j] = sum;
            }
        }

        int maxi = 0;
        for(auto it:arr) maxi = max(maxi, getMaximum(it));

        return maxi;
    }
};