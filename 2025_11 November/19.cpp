// https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/?envType=daily-question&envId=2025-11-19

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>st;
        for(auto it:nums)   st.insert(it);

        while(st.count(original)) original *= 2;

        return original;
    }
};