// https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/description/?envType=daily-question&envId=2026-03-20

class Solution {
private:
    int findMini(vector<vector<int>>& grid, int cr, int cc, int k, int n, int m) {
        // if not possible to form a k*k submatrix
        if(cr + k > n || cc + k > m)  return INT_MAX;

        // if only 1*1 matrix
        if(k == 1)  return 0;

        set<int>st;
        for(int i = cr; i < cr+k; i++) {
            for(int j = cc; j < cc+k; j++) {
                st.insert(grid[i][j]);
            }
        }

        // if all elements are same
        if(st.size() == 1)  return 0;

        int num1 = INT_MAX;
        int mini = INT_MAX;
        for(auto num2:st) {
            if(num1 == INT_MAX)   num1 = num2;
            else {
                mini = min(mini, abs(num2-num1));
                num1 = num2;
            }
        }

        return mini;
    }
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>ans;
        for(int i = 0; i < n; i++) {
            vector<int>curr;
            for(int j = 0; j < m; j++) {
                int mini = findMini(grid, i, j, k, n, m);
                if(mini != INT_MAX) curr.push_back(mini);
            }

            if(curr.size() > 0) ans.push_back(curr);
        }

        return ans;
    }
};