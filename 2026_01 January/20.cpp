// https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/?envType=daily-question&envId=2026-01-20

class Solution {
private:
    int get(int num) {
        int i = 0;
        while(i < num) {
            int orVal = i | (i+1);
            if(orVal == num) return i;

            i++;
        }

        return -1;
    }
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int& num : nums)
            ans.push_back(get(num));

        return ans;
    }
};