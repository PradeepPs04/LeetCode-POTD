// https://leetcode.com/problems/maximal-rectangle/?envType=daily-question&envId=2026-01-11

class Solution {
private:
    int max_histogram(vector<int>& heights)
    {
        stack<int>st;
        int n = heights.size();
        int ans = 0;

        for(int i = 0; i <= n; i++)
        {
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                
                ans = max(ans, height * width);
            }
            st.push(i);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if(matrix.size() == 0)  return 0;
        vector<int>heights(matrix[0].size(), 0);
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            int area = max_histogram(heights);
            ans = max(ans, area);
        }  
        return ans;
    }
};