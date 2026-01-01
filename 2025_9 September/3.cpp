// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/?envType=daily-question&envId=2025-09-03

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // sort array according to 
            // arr[0] in ascending order and arr[1] in descending order
        sort(points.begin(), points.end(), [](const vector<int>&a, const vector<int>&b) {
            if(a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] > b[1];
        });

        int ans = 0;

       for(int i = 0; i < points.size()-1; i++) {
            int xMin = points[i][0]-1;
            int xMax = INT_MAX;
            int yMin = INT_MIN;
            int yMax = points[i][1] + 1;

            for(int j = i+1; j < points.size(); j++) {
                if(points[j][0] > xMin && points[j][0] < xMax && points[j][1] > yMin && points[j][1] < yMax) {
                    ans++;
                    xMin = points[j][0];
                    yMin = points[j][1];   
                }
            }
       }

       return ans;
    }
};