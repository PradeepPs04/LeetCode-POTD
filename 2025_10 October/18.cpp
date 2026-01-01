// https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/?envType=daily-question&envId=2025-10-18

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        if(nums.size() == 0)    return 0;
        
        // make every element as smallest as possible
        int cnt = 1;
        int prev = nums[0] - k; // used number for 1st element

        for(int i = 1; i < nums.size(); i++) {
            // smallest element that is to be used for current element
            int curr = prev + 1;

            // if it's in range of (num-k to num+k)
            if(curr >= nums[i]-k && curr <= nums[i]+k) {
                cnt++;
                prev++;
            }
            // if not in range
            // it menas either we can't create more distict elements from current element (e.g. 1,1,1,1, k = 1, here we can only create 3 distinct elements)

            // if current number is more than prevNumber + k it means that we can make current element as smallest as nums[i] - k 
            // and we will continue the steps from next elements
            else if(prev < nums[i] - k) {
                cnt++;
                prev = nums[i] - k;
            }
        }

        return cnt;
    }
};