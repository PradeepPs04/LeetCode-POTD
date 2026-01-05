// https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2026-01-05

#define ll long long

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        ll sum = 0;
        int negative_cnt = 0; // stores total negative number counts

        for(auto it:matrix) {
            for(auto jt:it) {
                negative_cnt += (jt < 0); // negative count
                sum = sum + (ll)abs(jt);
                mini = min(mini, abs(jt));
            }
        }

        // if odd number of -ve's then we can make all +ve's except one number (so make sure it's the minimum one)
        // if even number of -ve's then we can make all +ve's (sum of matrix)
        return (negative_cnt & 1  ? sum - (mini*2) : sum);
    }
};