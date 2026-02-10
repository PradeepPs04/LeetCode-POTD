// https://leetcode.com/problems/longest-balanced-subarray-i/description/?envType=daily-question&envId=2026-02-10

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++) {
            unordered_set<int>st;
            int evenCnt = 0;
            for(int j = i; j < nums.size(); j++) {
                // increase even count
                if(nums[j] % 2 == 0 && !st.count(nums[j]))  evenCnt++;
                // insert into set
                st.insert(nums[j]);
                
                // if equal number of even and odd
                if(evenCnt == st.size() - evenCnt)  maxi = max(maxi, j-i+1);
            }
        }

        return maxi;
    }
};