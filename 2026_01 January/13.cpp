// https://leetcode.com/problems/separate-squares-i/description/?envType=daily-question&envId=2026-01-13

class Solution {
private:
    bool check(vector<vector<int>>& squares, double mid_y, double total) {
        // bottom area below the line
        double bottom_area = 0.0;

        for(auto &it:squares) {
            double y = it[1];
            double l = it[2];

            double bottomY = y;
            double topY = y + l;

            // if line is above the current square
            if(mid_y >= topY)   bottom_area += l*l;
            // if line is intersecting current square
            else if(mid_y > bottomY)    bottom_area += (mid_y - bottomY) * l;
        }

        // bottom area must be equal to the half of the total area
        return bottom_area >= total/2.0;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = INT_MAX;
        double high = INT_MIN;
        double total = 0.0;

        // calculate total area and get most topY and most bottomY coordinates
        for(auto &it:squares) {
            double x = it[0];
            double y = it[1];
            double l = it[2];
            total += l*l;

            low = min(low, y);
            high = max(high, y+l);
        }

        double ans_y = 0.0;

        // binary search on line coordinates to find answer
        while(high-low > 1e-5) {
            double mid_y = low + (high-low)/2.0;
            ans_y = mid_y;

            // if area above the line is more than area below the line (shift down)
            if(check(squares, mid_y, total))    high = mid_y;
            // if below area is more than shift up
            else    low = mid_y;
        }

        return ans_y;
    }
};