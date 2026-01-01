// https://leetcode.com/problems/maximum-average-pass-ratio/description/?envType=daily-question&envId=2025-09-01

class Solution {
private:
    // calculates how much adding a sutdent to a class will affect ratio
    double calculateDelta(int pass, int total) {
        return (double)(pass+1) / (total+1) - (double)pass / total;
    }

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>>pq; // max heap {delta, {pass, total}}
        for(auto it:classes) {
            pq.push({calculateDelta(it[0], it[1]), {it[0], it[1]}});
        }

        while(extraStudents--) {
            // 
            int pass = pq.top().second.first;
            int total = pq.top().second.second;
            pq.pop();

            pq.push({calculateDelta(pass+1, total+1), {pass+1, total+1}});
        }

        double totalPassRatio = 0;
        while(!pq.empty()) {
            int pass = pq.top().second.first;
            int total = pq.top().second.second;
            pq.pop();

            totalPassRatio += (double)pass/total;
        }

        return totalPassRatio / classes.size();
    }
};