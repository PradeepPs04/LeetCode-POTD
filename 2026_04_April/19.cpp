// https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/?envType=daily-question&envId=2026-04-19

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int maxi = 0;

        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] <= nums2[j]) {
                if(i < j)   maxi = max(maxi, j-i);
                j++;
            } else i++;
        }

        return maxi;
    }
};