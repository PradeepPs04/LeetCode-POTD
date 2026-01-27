// https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/?envType=daily-question&envId=Invalid%20Date

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj[n];

        for(auto it:edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2*w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; // min heap {weight, node}

        vector<int>visited(n, 0); // visited array
        vector<int>distance(n, INT_MAX); // distance array (distance to node from source '0')
        distance[0] = 0; // distance from source to source is 0

        pq.push({0, 0});

        while(!pq.empty()) {
            int w = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node == n-1) return w;

            visited[node] = true;

            // go to all neighbour nodes
            for(auto it:adj[node]) {
                int nd = it[0];
                int wt = it[1];
                // if neighbour node was not visited earlier AND there is a shorter path to reach it
                if(!visited[nd] && w + wt < distance[nd]) {
                    pq.push({w + wt, nd});
                    distance[nd] = w + wt; // update the distancd to that node
                }
            }
        }

        return -1;
    }
};