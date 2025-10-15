// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description/?envType=daily-question&envId=2025-10-15

class Solution {
private:
    bool  possible(vector<int>& arr, int k) {
        for(int i = 0; i < arr.size(); i++) {
            // indices of first subarray
            int firstLeftIdx = i;   int firstRightIdx = i + k - 1;

            // indices of second subarray
            int secondLeftIdx = i + k;  int secondRightIdx = i + 2*k - 1;

            // check if possible to form subarray of size k
            if(firstRightIdx >= arr.size() || secondLeftIdx >= arr.size() || secondRightIdx >= arr.size()) break;

            // check if striclty increasing array of size k can be formed
            int firstSub = arr[firstRightIdx] - arr[firstLeftIdx] + 1;
            int secondSub = arr[secondRightIdx] - arr[secondLeftIdx] + 1;

            if(firstSub == k && secondSub == k) return true;
        }

        return false;
    }
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int>arr(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) arr[i] += arr[i-1];
            else    arr[i] = 1;
        }

        int low = 1;
        int high = nums.size() / 2;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(possible(arr, mid))  low = mid + 1;
            else high = mid - 1;
        }

        return high;
    }
};