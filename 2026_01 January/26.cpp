// https://leetcode.com/problems/minimum-absolute-difference/?envType=daily-question&envId=2026-01-26
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mini = INT_MAX;
        for(int i = 1; i < arr.size(); i++) mini = min(mini, arr[i]-arr[i-1]);

        vector<vector<int>>ans;
        for(int i=1; i<arr.size(); i++) {
            if(arr[i]-arr[i-1] == mini) ans.push_back({arr[i-1], arr[i]});
        }

        return ans;
    }
};
