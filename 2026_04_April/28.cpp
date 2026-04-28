// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/?envType=daily-question&envId=2026-04-28

class Solution {
private:
    int calculateMoves(int val,int x, vector<vector<int>>&grid) {
        int moves = 0;
        for(auto it:grid) {
            for(auto jt:it) {
                int diff = abs(val - jt);
                moves += (diff / x);
            }
        }
        
        return moves;
    }
   
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int val = grid[0][0];
        
        vector<int>arr;
        
        for(auto it:grid) {
            for(auto jt:it) {
                int diff = abs(val-jt);
                if(diff % x != 0)    return -1; 
                arr.push_back(jt);         
            }
        }
        
        sort(arr.begin(), arr.end());
        
        int size = arr.size();
        if(size % 2 == 0)    return min(calculateMoves(arr[size/2], x, grid), calculateMoves(arr[size/2-1], x, grid));
        
        return calculateMoves(arr[size/2], x, grid);
    }
};
