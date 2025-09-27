// https://leetcode.com/problems/largest-triangle-area/description/?envType=daily-question&envId=2025-09-27

class Solution {
double distance(vector<int>&a, vector<int>& b) {
    double x1 = a[0];
    double y1 = a[1];
    double x2 = b[0];
    double y2 = b[1];

    return hypot(x2-x1, y2-y1); // sqrt((x2-x1)^2 + (y2-y1)^2)
}
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        for(int i = 0; i < points.size(); i++) {
            for(int j = i + 1; j < points.size(); j++) {
                for(int k = j + 1; k < points.size(); k++) {
                    double a = distance(points[i], points[j]);
                    double b = distance(points[j], points[k]);
                    double c = distance(points[i], points[k]);

                    double s = (a + b + c) / 2;

                    double area = sqrt(s*(s-a)*(s-b)*(s-c));

                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
};