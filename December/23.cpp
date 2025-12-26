// https://leetcode.com/problems/two-best-non-overlapping-events/description/?envType=daily-question&envId=2025-12-23

class Solution {
private:
    int binSearch(vector<vector<int>>& events, int left, int prevEnd) {
        int right = events.size()-1;
        int idx = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(events[mid][0] > prevEnd)  {
                idx = mid;
                right = mid - 1;
            } else left = mid + 1;
        }

        return idx;
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end()); // sort the events according to starting date

        int n = events.size();
        vector<int>maxi(n); // array to store maximum value (maxi[i] means the maximum value for all events from i to n)
        maxi[n-1] = events[n-1][2];
        for(int i = n - 2; i >= 0; i--) {
            maxi[i] = max(events[i][2], maxi[i+1]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int curEnd = events[i][1];
            int val = events[i][2]; // select current event
            int idx = binSearch(events, i, curEnd); // search for first non-overlapping event
            if(idx > i && idx < n)  val += maxi[idx]; // get maximum value from all next non-overlapping events

            ans = max(ans, val); // get maximum value events
        }

        return ans;
    }
};