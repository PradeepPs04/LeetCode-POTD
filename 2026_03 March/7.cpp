// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/?envType=daily-question&envId=2026-03-07

// Brute
// TC: O(N)
// SC: O(N)
// modifies given string
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        s += s;

        string s1, s2;
        for(int i = 0; i < 2*n; i++) {
            s1 += (i&1) ? '0' : '1';
            s2 += (i&1) ? '1' : '0';
        }

        int cnt1 = 0, cnt2 = 0;
        int ans = INT_MAX;

        int left = 0, right = 0;
        while(right < 2*n) {
            // expand the window
            if(s[right] != s1[right])   cnt1++;
            if(s[right] != s2[right])   cnt2++;

            // shrink the window
            if(right - left + 1 > n) {
                if(s[left] != s1[left]) cnt1--;
                if(s[left] != s2[left]) cnt2--;

                left++;
            }

            if(right-left+1 == n)   ans = min(ans, min(cnt1, cnt2));

            right++;
        }

        return ans;
    }
};


// Better
// TC: O(N)
// SC: O(N)
// Not modifies given string
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        string s1, s2;
        for(int i = 0; i < 2*n; i++) {
            s1 += (i&1) ? '0' : '1';
            s2 += (i&1) ? '1' : '0';
        }

        int cnt1 = 0, cnt2 = 0;
        int ans = INT_MAX;

        int left = 0, right = 0;
        while(right < 2*n) {
            // expand the window
            if(s[right % n] != s1[right])   cnt1++;
            if(s[right % n] != s2[right])   cnt2++;

            // shrink the window
            if(right - left + 1 > n) {
                if(s[left % n] != s1[left]) cnt1--;
                if(s[left % n] != s2[left]) cnt2--;

                left++;
            }

            if(right-left+1 == n)   ans = min(ans, min(cnt1, cnt2));

            right++;
        }

        return ans;
    }
};


// Optimum
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        // s1 -> odd_index ? '0' : '1'
        // s2 -> odd_index ? '1' : '0'

        int cnt1 = 0, cnt2 = 0;
        int ans = INT_MAX;

        int left = 0, right = 0;
        while(right < 2*n) {
            // expand the window
            char s1Right = (right & 1) ? '0' : '1';
            char s2Right = (right & 1) ? '1' : '0';
            if(s[right % n] != s1Right)   cnt1++;
            if(s[right % n] != s2Right)   cnt2++;

            // shrink the window
            if(right - left + 1 > n) {
                char s1Left = (left & 1) ? '0' : '1';
                char s2Left = (left & 1) ? '1' : '0';
                if(s[left % n] != s1Left) cnt1--;
                if(s[left % n] != s2Left) cnt2--;

                left++;
            }

            if(right-left+1 == n)   ans = min(ans, min(cnt1, cnt2));

            right++;
        }

        return ans;
    }
};