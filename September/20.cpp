// https://leetcode.com/problems/implement-router/description/?envType=daily-question&envId=2025-09-20

class Router {
private:
    map<vector<int>, int>mpp; // [{src, dest, time}] // to track duplicates
    queue<vector<int>>q; // [{src, dest, time}] // store packets
    unordered_map<int, vector<int>>timestamps; // {dest: [time]}
    unordered_map<int, int>skip; // skip elements to get the starting index for binary search
    int maxSize;
public:
    Router(int memoryLimit) {
        maxSize = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int>packet = {source, destination, timestamp};

        // check for duplicate
        if(mpp.find(packet) != mpp.end())   return false;

        // check if queue is full 
        if(q.size() == maxSize) {
            vector<int>p = q.front();
            mpp.erase(p);
            int dest = p[1];

            // while counting for packets of this dest
            // we need to skip removed packets
            skip[dest]++;
            q.pop();
        }

        q.push(packet);
        mpp[packet]++;
        timestamps[destination].push_back(timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        // if no packets
        if(q.empty())   return {};

        vector<int>res = q.front();
       
        q.pop();    
        mpp.erase(res);

        // one packet removed 
        // one more packet to be skipped while counting
        int dest = res[1];
        skip[dest]++;

        return res;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        // if no packets with correspoinding destination
        if(timestamps.find(destination) == timestamps.end())    return 0;

        vector<int>&arr = timestamps[destination];
        int skip_count = skip[destination];

        auto left = lower_bound(arr.begin() + skip_count, arr.end(), startTime);
        auto right = upper_bound(arr.begin() + skip_count, arr.end(), endTime);

        return int(right - left);
    }
};