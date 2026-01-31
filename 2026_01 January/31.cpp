// https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/?envType=daily-question&envId=2026-01-31

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size()-1;
        int ansIdx = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(letters[mid] > target) {
                ansIdx = mid;
                high = mid - 1;
            }
            else    low = mid + 1;
        }

        return ansIdx == -1 ? letters[0] : letters[ansIdx];
    }
};