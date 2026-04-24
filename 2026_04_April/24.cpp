// https://leetcode.com/problems/furthest-point-from-origin/?envType=daily-question&envId=2026-04-24

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0;
        int right = 0;
        for(auto it:moves) {
            left += it == 'L';
            right += it == 'R';
        }
        
        int total = moves.length();
        int dash = total - (left + right);
        
        int ans = max(left, right) - min(left, right) + dash;
        
        return ans;
    }
};
