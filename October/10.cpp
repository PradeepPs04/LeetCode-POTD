// https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/?envType=daily-question&envId=2025-10-10

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int>dp(energy.size(), 0);

        int ans = INT_MIN;
        for(int i = energy.size()-1; i >= 0; i--) {
            dp[i] = energy[i];
            // if there is a valid next step
            if(i + k < energy.size())   dp[i] += dp[i + k];
            ans = max(ans, dp[i]);
        }   

        return ans;
    }
};