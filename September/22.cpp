// https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2025-09-22

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>mpp(101, 0);
        int maxFreq = 0;
        int cnt = 0;

        for(int val:nums) {
            mpp[val]++;
            if(mpp[val] == maxFreq) cnt++; // similar element with maximum frequency
            else if(mpp[val] > maxFreq) {
                // new maximum frequency found
                maxFreq = mpp[val];
                cnt = 1;
            }
        }

        return maxFreq * cnt;
    }
};