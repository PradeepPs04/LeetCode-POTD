// https://leetcode.com/problems/water-bottles/?envType=daily-question&envId=2025-10-01

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = numBottles;
        while(numBottles >= numExchange) {
            int refil = numBottles / numExchange;
            int empty = numBottles % numExchange;
            cnt += refil;

            numBottles = refil + empty;
        }

        return cnt;
    }
};