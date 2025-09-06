// https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/description/?envType=daily-question&envId=2025-09-06

#define ll long long

class Solution {
private:
    ll get(int left, int right) {
        ll l = 1, r = 3;
        ll cnt = 0;
        ll steps = 1;

        while(l <= right) {
            ll first = max(l, (ll)left);
            ll second = min(r, (ll)right);

            if(first <= second) {
                ll length = second-first+1;
                cnt += length*steps;
            }
            steps++;

            l = r+1;
            r = 4*l - 1;
        }

        return ceil(cnt/2.0);
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        ll ans = 0;
        for(auto it:queries) {
            ans += get(it[0], it[1]);
        }        

        return ans;
    }
};