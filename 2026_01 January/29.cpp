// https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/?envType=daily-question&envId=2026-01-29

#define ll long long

class Solution {
private:
    void dijkstra(int src, vector<pair<int, int>>adj[], vector<int>&distance) {
        distance[src] = 0;

        typedef pair<int, int> pp;
        priority_queue<pp, vector<pp>, greater<pp>>pq; // min heap {cost, node}

        pq.push({0, src}); // push source node with 0 cost to heap
        while(!pq.empty()) {
            ll cost = pq.top().first; // cost so far
            int node = pq.top().second; // current node
            pq.pop();

            // old path pushed in heap earlier (skip if inefficient)
            if(cost > distance[node])   continue;

            // go to all neighbour nodes
            for(auto it:adj[node]) {
                int nd = it.first;
                ll cst = it.second;

                // if a path with shorter distance is found
                if(cost + cst < distance[nd]) {
                    pq.push({cost + cst,  nd});
                    distance[nd] = cost + cst;
                }
            }
        } 
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        if(source.length() != target.length())  return -1;

        vector<pair<int, int>>adj[26];

        for(int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int c = cost[i];

            adj[u].push_back({v, c});
        }

        vector<vector<int>>distance(26, vector<int>(26, INT_MAX)); // distance to all nodes from nodes from all nodes
        for(int i = 0; i < 26; i++) {
            dijkstra(i, adj, distance[i]);
        }

        ll totalCost = 0;
        for(int i = 0; i < source.size(); i++) {
            int src = source[i] - 'a';
            int dest = target[i] - 'a';

            // if source is same as destination
            if(src == dest) continue;

            // if no path is found from source to destination
            if(distance[src][dest] == INT_MAX)  return -1;

            totalCost += distance[src][dest];
        }

        return totalCost;
    }
};