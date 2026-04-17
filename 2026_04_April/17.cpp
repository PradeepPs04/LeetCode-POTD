// https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/description/?envType=daily-question&envId=2026-04-17

class Solution {
private:
    void reverseString(string& s) {
        int i = 0;
        int j = s.length()-1;
        while(i < j)    swap(s[i++], s[j--]);
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int>mpp;
        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            string s = to_string(num);
            reverseString(s);
            int revNum = stoi(s);

            // if any reverse is same as current num
            if(mpp.count(num))  mini = min(mini, i-mpp[num]);

            // store index of reverse of current num
            mpp[revNum] = i;
        }

        return mini == INT_MAX ? -1 : mini;
    }
};