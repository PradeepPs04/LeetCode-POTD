// https://leetcode.com/problems/largest-perimeter-triangle/description/?envType=daily-question&envId=2025-09-28

class Solution {
private: 
    bool valid(int a, int b, int c) {
        if(a + b <= c || b + c <= a || a + c <= b)  return false;
        return true;
    }
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = nums.size() - 3; i >= 0; i--) {
           if(valid(nums[i], nums[i+1], nums[i+2])) return nums[i] + nums[i+1] + nums[i+2];
        }

        return 0;
    }
};