// https://leetcode.com/problems/minimum-penalty-for-a-shop/description/?envType=daily-question&envId=2025-12-26

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int>prevN(n+1, 0); // stores how many 'N' are there before current day
        vector<int>nextY(n+1, 0); // stores how many 'Y' are there after current day

        int nCnt = 0;
        for(int i = 0; i < n; i++) {
            prevN[i] = nCnt;
            if(customers[i] == 'N') nCnt++;
        }
        prevN[n] = nCnt; // for (array.size())th day

        int yCnt = 0;
        for(int i = n-1; i >= 0; i--) {
            nextY[i] = yCnt;
            if(customers[i] == 'Y') yCnt++;
        }


        int miniPenalty = INT_MAX;
        int ans = 0; 

        for(int i = 0; i < n; i++) {
            // close the shop on the ith day 
            // previous day that no customer came + upcoming days when costomer will come
            int currPenalty = prevN[i] + nextY[i];
            if(customers[i] == 'Y') currPenalty += 1; // if customer is coming today

            if(currPenalty < miniPenalty) {
                miniPenalty = currPenalty;
                ans = i;
            }
        }

        // if opening shop for all days gives minimum penalty
        if(prevN[n] < miniPenalty) {
            miniPenalty = prevN[n]; // penalty will be the count of days when no customer came
            ans = n; // shop remained open for all days
        }

        return ans;
    }
};