#include <bits/stdc++.h>
using namespace std;
/**
 * @思路 
 * 两个节点的连接边数量相加再减去二者的重合边
 * 
 */
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n, vector<int>(n, 0)); 
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0], v = roads[i][1];
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        int maxRank = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++) {
                int rankI = accumulate(adj[i].begin(), adj[i].end(), 0);
                int rankJ = accumulate(adj[j].begin(), adj[j].end(), 0);
                int rankSum = rankI + rankJ - ((adj[i][j] == 1) ? 1 : 0);
                maxRank = max(maxRank, rankSum);
            }
        return maxRank;
    }
};
int main() {


    return 0;
}