// https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/?envType=daily-question&envId=2025-11-22

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        for(int &num: nums) {
            int val = num % 3;
            cnt += min(abs(val-0), abs(3-val));
        }

        return cnt;
    }
};