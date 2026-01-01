// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/?envType=daily-question&envId=2025-09-07

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;

        // add pairs of -ve & +ve 
        for(int i = 1; i <= n/2; i++) {
            ans.push_back(i);
            ans.push_back(-i);
        }

        // if n id odd then add 0
        if(n & 1)   ans.push_back(0);

        return ans;
    }
};