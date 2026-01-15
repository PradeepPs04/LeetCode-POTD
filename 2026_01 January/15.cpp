// https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/?envType=daily-question&envId=2026-01-15

class Solution {
private:
    int getMaxConsecutiveLength(vector<int>& arr) {
        int maxi = 1;
        int i = 0;
        while(i < arr.size()) {
            int j = i + 1;
            while(j < arr.size() && arr[j] == arr[j-1]+1)   j++;
            int len = j-i;
            maxi = max(maxi, len);
            i = j;
        }

        return maxi;
    }
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxH = getMaxConsecutiveLength(hBars);
        int maxV = getMaxConsecutiveLength(vBars);

        int side =  min(maxH, maxV) + 1;

        return side * side;
    }
};