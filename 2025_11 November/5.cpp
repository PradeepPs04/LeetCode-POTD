// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/description/?envType=daily-question&envId=2025-11-05

class Solution {
private:
    long long sum; // sum of top x frequent elements
    set<pair<int, int>>main; // main set (stores top x frequent elements)
    set<pair<int, int>>sec; // secondary set (stores rest elements)

    void insertInSet(pair<int, int>p, int x) {
        // if main set has less elements than x
        // or new pair is larger than previously inserted pairs in main set
        if(main.size() < x || p > *main.begin()) {
            sum += (long long)p.first * (long long)p.second;
            main.insert(p);

            if(main.size() > x) {
                // remove smallest from main set
                auto smallest = *main.begin();
                sum -= (long long)smallest.first * (long long)smallest.second;
                main.erase(smallest);

                // insert into secondary set
                sec.insert(smallest);
            }
        } else {
            sec.insert(p);
        }
    }

    void removeFromSet(pair<int, int>p) {
        // check in main set
        if(main.find(p) != main.end()) {
            sum -= (long long)p.first * (long long)p.second;
            main.erase(p);

            // insert largest pair from secondary set to main set
            if(sec.size() > 0) {
                // remove largest from secondary set
                auto largest = *sec.rbegin();
                sec.erase(largest);

                // insert into main set
                main.insert(largest);
                sum += (long long)largest.first * (long long)largest.second;
            }
        } else {
            sec.erase(p);
        }
    }
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int>mpp;
        vector<long long>ans;

        int left = 0;
        int right = 0;

        while(right < nums.size()) {
            if(mpp[nums[right]] > 0) {
                removeFromSet({mpp[nums[right]], nums[right]});
            }

            mpp[nums[right]]++;
            insertInSet({mpp[nums[right]], nums[right]}, x);

            // if subarray of k is formed
            if(right - left + 1 == k) {
                ans.push_back(sum);
                removeFromSet({mpp[nums[left]], nums[left]});
                mpp[nums[left]]--;

                if(mpp[nums[left]] == 0)    mpp.erase(nums[left]);
                else    insertInSet({mpp[nums[left]], nums[left]}, x);
                
                left++;
            }

            right++;
        }

        return ans;
    }
};