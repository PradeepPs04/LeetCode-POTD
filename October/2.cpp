// https://leetcode.com/problems/water-bottles-ii/description/?envType=daily-question&envId=2025-10-02

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drink = 0;
        int empty = 0;

        while(1) {
            drink += numBottles;
            empty += numBottles;
            numBottles = 0;

            // if no bottles to exchange
            if(empty < numExchange) break;

            while(empty >= numExchange) {
                numBottles++;
                empty -= numExchange;
                numExchange++;
            }
        }

        return drink;
    }
};