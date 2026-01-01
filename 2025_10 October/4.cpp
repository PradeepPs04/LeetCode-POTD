// https://leetcode.com/problems/container-with-most-water/description/?envType=daily-question&envId=2025-10-04

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        
        int maxi = 0;
        while(left < right) {
            int area = min(height[left], height[right]) * (right - left);
            maxi = max(maxi, area);

            if(height[left] < height[right])    left++;
            else    right--;
        }

        return maxi;
    }
};