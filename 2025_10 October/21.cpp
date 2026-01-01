// https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/description/?envType=daily-question&envId=2025-10-21

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // sort array in ascending order
        sort(nums.begin(), nums.end());

        // count frequency of each elements 
        // (we can use this to check how many elements are there 
        //that doesn't requird to be changed 
        // when converting to required element)
        unordered_map<int, int>mpp;
        for(auto it:nums)    mpp[it]++;

        int ans = 0;
        int startIdx = 0; // index of left most element that can be converted to required element
        int endIdx = 0; // index of right most element that can be converted to required element

        for(int requiredElement = nums[0]; requiredElement <= nums[nums.size()-1]; requiredElement++) {
            // get the index of left most possible candidate that can be converted to requiredElement
            while(nums[startIdx] < requiredElement - k) startIdx++;

            // get the index of right most possible candidate that can be converted to requiredElement
            while(endIdx < nums.size() && nums[endIdx] <= requiredElement + k)  endIdx++;

            int candidates = endIdx - startIdx; // number of candidates that can be converted
            int maxConversion = mpp[requiredElement] + numOperations; // maximum conversions that are allowed
            int achievableFrequency = min(candidates, maxConversion); // maximum frequency that  you can achieve by converting candidated to requiredElement

            ans = max(ans, achievableFrequency);
        }

        return ans;
    }
};