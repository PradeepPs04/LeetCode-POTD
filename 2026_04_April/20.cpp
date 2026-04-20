// https://leetcode.com/problems/two-furthest-houses-with-different-colors/description/?envType=daily-question&envId=2026-04-20

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxi = 0;
        for(int i = 0; i < colors.size(); i++) {
            for(int j = i+1; j < colors.size(); j++) {
                if(colors[i] != colors[j])  maxi = max(maxi, j-i);
            }
        }

        return maxi;
    }
};