#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges,
                            vector<int>& disappear) {
        vector<int> res(n, -1);
        res[0] = 0;
        vector<vector<pair<int, int>>> graph(n);
        for (auto&& edge : edges) {
            int ui = edge[0], vi = edge[1], li = edge[2];
            graph[ui].emplace_back(vi, li);
            graph[vi].emplace_back(ui, li);
        }

        // Dijkstra
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;
        minHeap.push({0, 0});
        while (!minHeap.empty()) {
            auto [d, u] = minHeap.top();
            minHeap.pop();
            if (d != res[u]) continue;
            for (auto&& [v, wi] : graph[u]) {
                if (d + wi < disappear[v] &&
                    (res[v] == -1 || d + wi < res[v])) {
                    res[v] = d + wi;
                    minHeap.push({res[v], v});
                }
            }
        }
        return res;
    }
};
int main() { return 0; }