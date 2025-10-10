// https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/description/?envType=daily-question&envId=2025-10-10

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int m = mana.size();
        int n = skill.size();

        vector<long long>finishTime(n, 0);

        for(int j = 0; j < m; j++) {
            // give potion to wizards as soon as they are free to take it
            finishTime[0] += mana[j] * skill[0];
            
            for(int i = 1; i < n; i++) {
                finishTime[i] = max(finishTime[i], finishTime[i-1]) + (long long)mana[j] * (long long)skill[i];
            }

            // synchronize time of all wizards for the potion
            for(int i = n-1; i > 0; i--) {
                finishTime[i-1] = finishTime[i] - (long long)mana[j] * (long long)skill[i];
            }
        }

        return finishTime[n-1];
    }
};