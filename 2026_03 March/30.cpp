// https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/?envType=daily-question&envId=2026-03-30

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string odd1, odd2;
        string even1, even2;
        for(int i = 0; i < s1.length(); i++) {
            if(i & 1) {
                odd1 += s1[i];
                odd2 += s2[i];
            } else {
                even1 += s1[i];
                even2 += s2[i];
            }
        }

        sort(odd1.begin(), odd1.end());
        sort(odd2.begin(), odd2.end());

        sort(even1.begin(), even1.end());
        sort(even2.begin(), even2.end());

        return (odd1 == odd2 && even1 == even2);
    }
};