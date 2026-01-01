// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/?envType=daily-question&envId=2025-10-08

class Solution {
private:
    int findLeftMost(vector<int>& arr, int k, long long target) {
        int low = 0;
        int high = arr.size() - 1;

        while(low <= high) {
            int mid = (low + high) / 2;
            long long curr = (long long)arr[mid] * (long long)k;
            if(curr >= target)  high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        vector<int>ans;
        for(auto it:spells) {
            // search for left most index that will form a succcessful pair
            int left = findLeftMost(potions, it, success);
            // int right = potions.size(); 
            int cnt = potions.size() - left;
            ans.push_back(cnt);           
        }

        return ans;
    }
};