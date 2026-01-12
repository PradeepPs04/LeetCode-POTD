// https://leetcode.com/problems/minimum-time-visiting-all-points/?envType=daily-question&envId=2026-01-12

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 1; i < points.size(); i++) {
            int a = points[i-1][0]; int b = points[i-1][1];
            int c = points[i][0];   int d = points[i][1];
        
            int dist1 = abs(c-a);
            int dist2 = abs(d-b);

            if(dist1 < dist2)  ans += (dist1 + (dist2 - dist1));
            else    ans += (dist2 + (dist1 - dist2));
        }

        return ans;
    }
};