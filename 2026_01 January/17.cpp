// https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/description/?envType=daily-question&envId=2026-01-17

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int maxSide = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                // width
                int topRightX = min(topRight[i][0], topRight[j][0]);
                int bottomLeftX = max(bottomLeft[i][0], bottomLeft[j][0]);
                int width = topRightX - bottomLeftX;

                // height
                int topRightY = min(topRight[i][1], topRight[j][1]);
                int bottomRightY = max(bottomLeft[i][1], bottomLeft[j][1]);
                int height = topRightY - bottomRightY;

                int side = min(width, height);

                maxSide = max(maxSide, side);
            }
        }

        return (long long)maxSide * (long long)maxSide;
    }
};