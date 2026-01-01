// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/?envType=daily-question&envId=2025-11-03

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // get the range (duplicates wale)
        // get sum of the range
        // get the maximum of range

        // we will remove all elements except maximum (because that will take the most time)

        int totalTime = 0;

        int idx = 0;
        while(idx < colors.length()) {
            int sum = 0;
            int maxi = 0;

            char ch = colors[idx];
            while(idx < colors.length() && colors[idx] == ch) {
                sum += neededTime[idx];
                maxi = max(maxi, neededTime[idx]);
                idx++;
            }

            totalTime += (sum - maxi);
        }

        return totalTime;
    }
};