// https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/?envType=daily-question&envId=2026-01-23

#define ll long long

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        vector<ll>temp(n);
        for(int i=0; i<n; i++)  temp[i] = nums[i];

        set<pair<ll, int>>minPairSet; // {pair_sum, first elem index}

        vector<int>nextIndex(n); // next index of element
        vector<int>prevIndex(n); // prev index of element

        for(int i = 0; i < n; i++) {
            nextIndex[i] = i + 1;
            prevIndex[i] = i - 1;
        }

        int badPairs = 0; // count of unsorted pairs
        for(int i = 0; i < n-1; i++) {
            // check for bad pair 
            if(temp[i] > temp[i+1]) badPairs++;

            // store sum of pairs and first index of pair in set
            minPairSet.insert({temp[i] + temp[i+1], i});
        }

        int operations = 0; // number of operations to make array sorted

        // while there are any badPairs left
        while(badPairs > 0) {
            int first = minPairSet.begin()->second; // index of first element
            int second = nextIndex[first]; // index of second element

            int first_left = prevIndex[first]; // index of element on the left of first element
            int second_right = nextIndex[second]; // index of element on the right of second element

            minPairSet.erase(begin(minPairSet)); // remove minimum pair from set

            // if it was a bad pair
            if(temp[first] > temp[second])  badPairs--;

            // check for bad pair on the left of current pair
            // {d, (a,b)}
            
            if(first_left >= 0) { // left index should be a valid index
                // if the left element was making a bad pair earlier but has become good pair now
                if(temp[first_left] > temp[first] && temp[first_left] <= temp[first] + temp[second])    badPairs--;
                // if it was a good pair but has become a bad pair
                else if(temp[first_left] <= temp[first] && temp[first_left] > temp[first] + temp[second])   badPairs++;
            }

            // check for bad pair on the right of current pair
            // {(a,b), d}

            if(second_right < n) { // right index should be a valid index
                // if the right element was good pair but has become a bad pair
                if(temp[second_right] >= temp[second] && temp[second_right] < temp[first] + temp[second])   badPairs++;
                // if bad pair has become a good pair
                else if(temp[second_right] < temp[second] && temp[second_right] >= temp[first] + temp[second])  badPairs--;
            }

            if(first_left >= 0) {
                // remove left pair
                minPairSet.erase({temp[first_left] + temp[first], first_left});
                // insert new pair
                minPairSet.insert({temp[first_left] + temp[first] + temp[second], first_left});
            }

            if(second_right < n) {
                // remove right pair
                minPairSet.erase({temp[second] + temp[second_right], second});
                // insert new pair
                minPairSet.insert({temp[first] + temp[second] + temp[second_right], first});

                prevIndex[second_right] = first;
            }

            nextIndex[first] = second_right;
            temp[first] += temp[second];

            operations++;
        }
        return operations;
    }

};