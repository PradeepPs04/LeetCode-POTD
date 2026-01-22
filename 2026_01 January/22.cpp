// https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/?envType=daily-question&envId=2026-01-22

class Solution {
private:
    bool isSorted(vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1])
                return false;
        }

        return true;
    }

public:
    int minimumPairRemoval(vector<int>& arr) {
        int cnt = 0;
        while (!isSorted(arr)) {
            int idx = 0;
            int sum = INT_MAX;

            for (int i = 0; i < arr.size() - 1; i++) {
                int cur_sum = arr[i] + arr[i + 1];
                if (cur_sum < sum) {
                    idx = i;
                    sum = cur_sum;
                }
            }

            vector<int> temp;
            int i = 0;
            while (i < arr.size()) {
                if (i == idx) {
                    temp.push_back(sum);
                    i += 2;
                } else {
                    temp.push_back(arr[i]);
                    i++;
                }
            }

            cnt++;
            arr = temp;
        }

        return cnt;
    }
};