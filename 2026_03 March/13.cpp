// https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description/?envType=daily-question&envId=2026-03-13

class Solution {
private:
    int secondsToHeight(int work, long long seconds, int h) {
        long long low = 1; // minimum height the worker can reduce
        long long high = h; // maximum height the worker can reduce

        // search for the height that worker can reduce in this range
        while(low <= high) {
            long long mid = low + (high - low) / 2;

            // time taken to reduce height by mid
            long long cur_time = work * ((mid*(mid+1))/2);

            // if more time required than available time then search for smaller height
            if(cur_time > seconds)  high = mid - 1;

            // else try to find more height
            else    low = mid + 1; 
        }

        // return the height that worker can reduce within given seconds
        return high;
    }

    bool possible(int h, vector<int>& times, long long k) {
        int decreased = 0; // height decreased by all workers within k time

        for(auto it:times) {
            // calculate height for every worker that he can decrease within this time
            decreased += secondsToHeight(it, k, h);
        }   

        // check if we were able to decrease all height
        return decreased >= h;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long mini = *min_element(workerTimes.begin(), workerTimes.end());
        long long maxi = *max_element(workerTimes.begin(), workerTimes.end());

        // minimum seconds which is possible to decrease height (smallest worker decrease only 1 height)
        long long low = mini;

        // maximum seconds which is possible to decrease height (largest worker decrease all h height)
        long long high = maxi * (((long long)mountainHeight * ((long long)mountainHeight+1)) / 2);

        // search for answer in this range  
        while(low <= high) {
            long long mid = low + (high - low) / 2;

            // if possible to do all tasks within this time then try to decrease time more
            if(possible(mountainHeight, workerTimes, mid))  high = mid - 1;

            // else try with more time
            else    low = mid + 1;
        }

        return low;
    }
};