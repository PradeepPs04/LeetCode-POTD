// https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/?envType=daily-question&envId=2026-04-21

class Solution {
private:
    class DSU {
    public:
        vector<int>parent;
        DSU(int n) {
            parent.resize(n);
            for(int i = 0; i < n; i++)  parent[i] = i;
        }

        int find(int u) {
            if(parent[u] == u)  return u;

            return parent[u] = find(parent[u]);
        }

        void unionn(int u, int v) {
            int p_u = find(u);
            int p_v = find(v);

            if(p_u == p_v)  return;

            parent[p_v] = p_u;
        }
    };

    int checkDiff(vector<int>& source, vector<int>& target, vector<int>& arr) {
        // store frequencies of elements from source that are within same component
        unordered_map<int, int>mpp;
        for(auto it:arr) {
            int elem = source[it];
            mpp[elem]++;
        }    

        // now check if element of this component from target is not presnt in source
        int cnt = 0;
        for(auto it:arr) {
            int elem = target[it];
            if(mpp[elem] > 0)   mpp[elem]--;
            else    cnt++;
        }

        return cnt;
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        // the indices which are being swapped will belongs to the same set
        // e.g. swa(0,1) => both belongs to a single component (let say 0)
        // now the swap(1,2) => now these two will also belong to the same set 
        // but 1 was belonging to set 0 
        //      so 2 will also now belong to the set 0

        // all indices within a set can be swapped with anyone
        int n = source.size();
        DSU dsu(n);

        for(auto it:allowedSwaps) {
            int u = it[0];
            int v = it[1];

            if(dsu.find(u) != dsu.find(v)) dsu.unionn(u, v);
        }

        // store indices that belongs to the same set
        unordered_map<int, vector<int>>mpp;
        for(int i = 0; i < n; i++) {
            int u = i;
            int p_u = dsu.find(u);
            
            mpp[p_u].push_back(i);
        }

        // now check for every set
        int ans = 0;
        for(auto it:mpp) {
            vector<int>arr = it.second; // indices in this set

            // check how many elements are different when we arrange these indices
            ans += checkDiff(source, target, arr);
        }

        return ans;
    }
};