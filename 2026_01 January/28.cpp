// https://leetcode.com/problems/minimum-cost-path-with-teleportations/description/?envType=daily-question&envId=Invalid%20Date

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>visitedForReachK(k+1, 0);

        // Flatten all cells into a list
        vector<tuple<int, int, int>>list; // {cell_cost, i, j}
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)  list.push_back({grid[i][j], i, j});
        }

        // sort the list
        sort(list.begin(), list.end());

        vector<vector<vector<int>>>distance(n, vector<vector<int>>(m, vector<int>(k+1, INT_MAX))); // distance array (distance from source node with teleports done)

        typedef tuple<int, int, int, int> tup;
        priority_queue<tup, vector<tup>, greater<tup>>pq; // min heap {cost, teleports_done, i, j}

        pq.push({0, k, 0, 0}); 
        while(!pq.empty()) {
            auto tpl = pq.top();
            pq.pop();

            int cost = get<0>(tpl); // cost so far to reach the current cell
            int tele_rem = get<1>(tpl); // number of teleports remaining
            int i = get<2>(tpl); // current row
            int j = get<3>(tpl); // current column

            // if reached at destination
            if(i == n-1 && j == m-1)    return cost;

            int newCost;
            // go down
            if(i + 1 < n) {
                newCost = cost + grid[i+1][j];
                // if less cost path is found
                if(newCost < distance[i+1][j][tele_rem]) {
                    pq.push({newCost, tele_rem, i+1, j});
                    distance[i+1][j][tele_rem] = newCost; // update the cost
                }
            }

            // go right
            if(j + 1 < m) {
                newCost = cost + grid[i][j+1];
                // if less cost path is found
                if(newCost < distance[i][j+1][tele_rem]) {
                    pq.push({newCost, tele_rem, i, j+1});
                    distance[i][j+1][tele_rem] = newCost; // update the cost
                }
            }

            // check for teleports
            if(tele_rem > 0) {
                int itr = visitedForReachK[tele_rem];
                for(; itr < list.size(); itr++) {
                    auto [cst, ni, nj] = list[itr]; // {cost, row, col}

                    // if we can't teleport to any cell further (cost of that cell is greater)
                    if(cst > grid[i][j])    break;

                    // if less cost path is found
                    if(cost < distance[ni][nj][tele_rem-1]) {
                        pq.push({cost, tele_rem-1, ni, nj}); // teleport to cell with the same cost
                        distance[ni][nj][tele_rem-1] = cost; // update the cost
                    }
                }

                visitedForReachK[tele_rem] = itr; // update the position in array ()
            }
        }

        return -1;
    }
};