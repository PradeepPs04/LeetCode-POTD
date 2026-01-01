// https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/?envType=daily-question&envId=2025-09-16

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>ans;

        for(int it:nums) {
            // next number to be pushed
            int next = it;

            while(ans.size() != 0) {
                int curr = ans.back();
                int g = __gcd(curr, next);

                // if co-prime
                if(g == 1)  break;

                // remove last element
                ans.pop_back();

                // calculate lcm
                long lcm = ((long)curr * (long)next) / (long)g;
                next = (int)lcm;
            }

            // push lcm/number
            ans.push_back(next);
        }

        return ans;
    }
};