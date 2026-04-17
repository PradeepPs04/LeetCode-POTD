// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/description/?envType=daily-question&envId=2026-04-10

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>>mpp;

        for(int i = 0; i < nums.size(); i++) {
            mpp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for(auto it:mpp) {
            vector<int>temp = it.second;
            for(int idx = 2; idx < temp.size(); idx++) {
                int i = temp[idx-2];
                int j = temp[idx-1];
                int k = temp[idx];

                int curr = abs(i-j) + abs(j-k) + abs(k-i);
                ans = min(ans, curr);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};