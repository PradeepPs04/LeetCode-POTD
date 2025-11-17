// https://leetcode.com/problems/number-of-substrings-with-only-1s/?envType=daily-question&envId=2025-11-16

#define ll long long

class Solution {
private:
    int modd = 1e9 + 7;
    int calculate(long long n) {
        long long val = (((n % modd) * ((n + 1) % modd)) % modd) / 2;
        return (int)(val % modd);
    }

public:
    int numSub(string s) {
        int i = 0;
        int cnt = 0;
        while (i < s.length()) {
            if (s[i] == '1') {
                int j = i + 1;
                while (j < s.length() && s[j] == '1')
                    j++;

                cnt += (calculate((long long)(j - i))) % modd;

                i = j;
            } else
                i++;
        }

        return cnt;
    }
};