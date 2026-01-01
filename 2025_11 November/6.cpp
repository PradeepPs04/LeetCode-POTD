// https://leetcode.com/problems/power-grid-maintenance/description/?envType=daily-question&envId=2025-11-07

class Solution {
private:
    void dfs(int node, vector<int>adj[], int id, vector<int>& parent, vector<int>& visited, unordered_map<int, set<int>>& mpp) {
        parent[node] = id;
        visited[node] = true;
        mpp[id].insert(node);

        for(auto neighbour:adj[node]) {
            if(!visited[neighbour]) dfs(neighbour, adj, id, parent, visited, mpp);
        }
    }
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        // create adjacency list
        vector<int>adj[c+1];
        for(auto it:connections) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>parent(c+1);
        vector<int>visited(c+1, 0);
        unordered_map<int, set<int>>mpp;

        // call dfs to get all connected components (power grid)
        for(int i = 1;  i <= c; i++) {
            if(!visited[i]) dfs(i, adj, i, parent, visited, mpp);
        }

        vector<int>ans;
        for(auto it:queries) {
            int type = it[0];
            int node = it[1];
            int id = parent[node];
            // if query is requesting connection
            if(type == 1) {
                // if no connections are available in that power grid
                if(mpp[id].size() == 0) ans.push_back(-1);
                else {
                    // check if the requesting node is availalbe
                    if(mpp[id].find(node) != mpp[id].end()) ans.push_back(node);
                    // get the smallest node in that power grid
                    else    ans.push_back(*(mpp[id].begin()));
                }
            } else {
                // query is to make the node offline
                mpp[id].erase(node);
            }
        }

        return ans;
    }   
};