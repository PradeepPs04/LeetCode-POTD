// https://leetcode.com/problems/mirror-distance-of-an-integer/?envType=daily-question&envId=2026-04-18

class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        int rev = stoi(s);

        return abs(n-rev);
    }
};