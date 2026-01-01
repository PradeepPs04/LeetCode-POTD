// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/description/?envType=daily-question&envId=2025-10-13

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int i = 0;
        while (i < words.size()) {
            ans.push_back(words[i]);
            int j = i + 1;
            string temp1 = words[i];
            sort(temp1.begin(), temp1.end());
            while (j < words.size()) {
                string temp2 = words[j];
                sort(temp2.begin(), temp2.end());
                if (temp1 != temp2)
                    break;
                j++;
            }

            i = j;
        }

        return ans;
    }
};