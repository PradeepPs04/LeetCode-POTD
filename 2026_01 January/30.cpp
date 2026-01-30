// https://leetcode.com/problems/minimum-cost-to-convert-string-ii/description/?envType=daily-question&envId=2026-01-30

class Solution {
private:
    typedef long long ll;
    typedef pair<ll, string> P;

    ll BIG_VALUE = 1e10;
    unordered_map<string, vector<pair<string, ll>>>adj; // graph

    unordered_map<string, unordered_map<string, ll>>dijkstraMemo; // to avoid recalculating shortest paths for already calculated nodes

    vector<ll>dp; // dp array

    string sourceStr;
    string targetStr;
    set<int>validLengths; // lengths of substrings which can be changed 

    ll dijkstra(string src, string dest) {
        // if shortest path from src to dest is already calculated earlier
        if(dijkstraMemo[src].count(dest)) return dijkstraMemo[src][dest];

        priority_queue<P ,vector<P>, greater<P>>pq; // min heap {cost, string}
        
        unordered_map<string, ll>distance; // distance array (source to string)
        distance[src] = 0; // distance from source to source is 0

        // push source node to heap
        pq.push({0, src});

        while(!pq.empty()) {
            ll currCost = pq.top().first; // cost so far
            string node = pq.top().second; // current string
            pq.pop();

            if(node == dest)    return currCost; // if destination string is reached

            // go to all neighbours
            for(auto &neighbour: adj[node]) {
                string nd = neighbour.first;
                ll cost = neighbour.second;

                // if shorter path is found
                // if we are reaching at a node for the first time (since map has default value 0 so we need to store distance at that time too)
                if(!distance.count(nd) || currCost + cost < distance[nd]) {
                    distance[nd] = currCost + cost;
                    pq.push({currCost + cost, nd});
                }
            }
        }

        // if a path is found to destination
        ll finalCost = distance.count(dest) ? distance[dest] : BIG_VALUE;

        // return the cost
        return dijkstraMemo[src][dest] = finalCost;
    }

    ll solve(int idx) {
        // base case
        if(idx >= sourceStr.length()) return 0;

        // if value already calculated
        if(dp[idx] != -1)   return dp[idx]; // get value from dp array

        ll minCost = BIG_VALUE;

        // if current charcter is same in source and target strings then solve for next characters
        if(sourceStr[idx] == targetStr[idx])    minCost = solve(idx+1);

        // check for all possible substring conversions from current index
        for(auto &len: validLengths) {
            // no more valid substring
            if(idx + len > sourceStr.length())  break;

            // source substing of length 'len' from index 'idx' (this is what we have now)
            string sourceSub = sourceStr.substr(idx, len);

            // target substing of length 'len' from index 'idx' (this is what we want to achieve)
            string targetSub = targetStr.substr(idx, len);

            // if conversion not possible then skip this length
            if(!adj.count(sourceSub))   continue;
            
            // find shortest path to reach the target sub-string
            ll minPathCost = dijkstra(sourceSub, targetSub);

            // if path is not found
            if(minPathCost == BIG_VALUE)    continue; // skip this substring

            // check for reamining part on source string (we have achieved desired target in current substring, now we have to achieve the next reamaining part of the string)
            minCost = min(minCost, minPathCost + solve(idx + len));
        }
        
        return dp[idx] = minCost;
    }
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        sourceStr = source;
        targetStr = target;

        dp.assign(10001, -1);
        
        // create adjacency list (graph)
        for(int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        // valid lengths
        for(auto s:original) {
            validLengths.insert(s.length());
        }
        
        // solve recursively
        ll ans = solve(0);

        return ans == BIG_VALUE ? -1 : ans;
    }
};