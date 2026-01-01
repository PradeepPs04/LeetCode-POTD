// https://leetcode.com/problems/maximize-happiness-of-selected-children?envType=daily-question&envId=2025-12-25

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());

        long long total = 0;
        for(int i = 0; i < happiness.size(); i++) {
            // if can't pick more children
            // or happiness becomes zero
            if(k == 0 || (happiness[i] <= i)) break;  

            total += (happiness[i] - i); // i children picked earlier so happiness will decrease by i time for current child

            k--;
        }

        return total;
    }
};