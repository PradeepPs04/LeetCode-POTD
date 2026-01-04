// https://leetcode.com/problems/four-divisors/description/?envType=daily-question&envId=2026-01-04

class Solution {
private:
    int factors(int num) {
        int sum = 0;
        int cnt = 0;
        for(int i = 1; i*i <= num; i++) {
            if(num % i == 0) {
                int a = i;
                int b = num / a;

                // both factors are same (e.g.: 2*2 = 4)
                if(a == b) {
                    cnt += 1;
                    sum += a;
                } else {
                    cnt += 2;
                    sum += (a + b);
                }
            }
        }

        return cnt == 4 ? sum : 0;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto it:nums) {
            ans += factors(it);
        }

        return ans;
    }
};