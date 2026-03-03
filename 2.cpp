// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/?envType=daily-question&envId=2026-03-02

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        int zeros[n];

        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = n-1; j>=0; j--) {
                if(grid[i][j] == 1) break;
                cnt++;
            }

            zeros[i] = cnt;
        }

        int swaps = 0;

        for(int i = 0; i < n; i++) {
            int req = n-i-1;
            int j = i;
            while(j < n && zeros[j] < req)   j++;
            // if desired rows not found
            if(j == n)   return -1;

            while(j > i) {
                swap(zeros[j], zeros[j-1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};