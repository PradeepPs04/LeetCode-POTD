// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/description/?envType=daily-question&envId=2025-11-04

class Solution {
private:
    int getSum(unordered_map<int, int>& mpp, int x) {
        if(mpp.size() < x)  {
            int sum = 0;
            for(auto it:mpp)    sum += (it.first * it.second);
            return sum;
        }

        priority_queue<pair<int, int>>pq;
        for(auto it:mpp)    pq.push({it.second, it.first});

        int sum = 0;
        for(int i = 0; i < x; i++) {
            sum += pq.top().first * pq.top().second;
            pq.pop();
        }

        return sum;
    }
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int>mpp;

        for(int i = 0; i < k; i++)  mpp[nums[i]]++;

        vector<int>ans;
        ans.push_back(getSum(mpp, x));
        
        int left = 0;
        for(int right = k; right < nums.size(); right++) {
            mpp[nums[left]]--;
            if(mpp[nums[left]] == 0)    mpp.erase(nums[left]);
            mpp[nums[right]]++;
            ans.push_back(getSum(mpp, x));

            left++;
        }

        return ans;
    }
};