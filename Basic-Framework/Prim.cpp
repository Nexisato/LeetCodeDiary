/*
 * @Date: 2024-02-20 15:48:47
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0000-Basic-Framework/Prim.cpp
 * @Description: 基于优先队列 实现Prim算法，适合边稀疏的图
 */
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
// Prim
// 1. 从任意一个顶点开始，将其加入到最小生成树中
// 2. 从最小生成树中的顶点出发，找到一个到其他顶点的最小权值边，将其加入到最小生成树中
// 3. 重复步骤2，直到最小生成树中有n-1条边
//
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
int prim(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    int min_cost = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    vector<bool> visited(n, false);
    minHeap.push({0, start});
    while (!minHeap.empty()) {
        auto [weight, u] = minHeap.top();
        minHeap.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        min_cost += weight;
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] != INT_MAX) {
                minHeap.push({graph[u][v], v});
            }
        }
    }
    return min_cost;
}
int main() {
    vector<vector<int>> graph = {
        {0, 2, 4, 1, INT_MAX},
        {2, 0, INT_MAX, 3, INT_MAX},
        {4, INT_MAX, 0, INT_MAX, 3},
        {1, 3, INT_MAX, 0, 4},
        {INT_MAX, INT_MAX, 3, 4, 0}
    };
    int start = 0;
    cout << prim(graph, start) << endl;
    return 0;
}