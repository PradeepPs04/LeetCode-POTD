// https://leetcode.com/problems/closest-equal-element-queries/description/?envType=daily-question&envId=2026-04-16

class Solution {
private:
    int getDistance(int idx1, int idx2, int n) {
        int mini = INT_MAX;
        if(idx1 > idx2) {
            int normal = idx1 - idx2;
            int circular = n - idx1 + idx2; 
            mini = min(normal, circular);
        } else {
            int normal = idx2 - idx1;
            int circular = n - idx2 + idx1;
            mini = min(normal, circular);
        }

        return mini;
    }
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>>mpp; // {element: {indices}}

        for(int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }

        vector<int>closest(n, -1);

        for(auto it:mpp) {
            vector<int>arr = it.second;

            int m = arr.size();

            // if only 1 frequency
            if(m == 1) {
                closest[arr[0]] = -1;
                continue;
            }
            
            for(int i = 0; i < m; i++) {
                int prevIdx = arr[(i-1+m) % m];
                int nextIdx = arr[(i+1) % m];

                int dist1 = getDistance(prevIdx, arr[i], n);
                int dist2 = getDistance(nextIdx, arr[i], n);

                int miniDistance = min(dist1, dist2);

                closest[arr[i]] = miniDistance;
            }
        }

        vector<int>ans;
        for(auto it:queries) {
            ans.push_back(closest[it]);
        }

        return ans;
    }
};