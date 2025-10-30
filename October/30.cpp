// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/?envType=daily-question&envId=2025-10-30

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int total = target[0];
        for(int i=1; i<target.size(); i++){
            if(target[i] > target[i-1]) {
                total += target[i] - target[i-1];
            }
        }

        return total;
    }
};