// https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/?envType=daily-question&envId=2025-10-19

class Solution {
private:
    string add(string s, int a) {
        for(int i = 1; i < s.length(); i+=2) {
            int num = s[i] - '0';
            num = (num + a) % 10;
            s[i] = '0' + num;
        }

        return s;
    }

    string rotate(string s, int b) {
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());
        reverse(s.begin(), s.end());

        return s;
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_map<string, bool>visited; // keeps track of generated strings
        queue<string>q;

        q.push(s); // push given string

        string ans = s;
        // generate all strings
        while(!q.empty()) {
            string curr = q.front();
            q.pop();

            ans = min(ans, curr);

            // add a to odd indices
            string s1 = add(curr, a);

            // rotate string right by b
            string s2 = rotate(curr, b);

            // check if string are generated earlier too
            if(!visited[s1]) {
                visited[s1] = true;
                q.push(s1);
            }
            if(!visited[s2]) {
                visited[s2] = true;
                q.push(s2);
            }
        }

        return ans;
    }
};