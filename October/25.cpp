// https://leetcode.com/problems/calculate-money-in-leetcode-bank/?envType=daily-question&envId=2025-10-25

class Solution {
private:
    int sum(int val) {
        return (val * (val + 1)) / 2;
    }
public:
    int totalMoney(int n) {
        int rounds = n / 7;
        int remaining = n % 7;

        int total = 0;
        for(int i = 0; i < rounds; i++) {
            total += sum(i+7) - sum(i);
        }

        total += sum(rounds + remaining) - sum(rounds);

        return total;
    }
};