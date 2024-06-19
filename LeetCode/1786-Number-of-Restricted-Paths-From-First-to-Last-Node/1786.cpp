/*
 * @Date: 2024-01-26 11:58:20
 * @Author: nexisato
 * @FilePath:
 * /LeetCodeDiary/LeetCode/1786-Number-of-Restricted-Paths-From-First-to-Last-Node/1786.cpp
 * @Description:
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// Dijkstra + DP
// 面试非常高频的题目
// tricks:
// - 用 unordered_map 代替 vector，好用又不占空间
// - 善用 C++ STL
// 1. Dijkstra 使用堆优化，避免超时
// 2. DP 从 n~1 递推，递推之前按照 dist 从小到大排序，记录好 idx
class Solution {
public:
	int countRestrictedPaths(int n, vector<vector<int>>& edges) {
		const int modulo = 1e9 + 7;
		int res = 0;
		unordered_map<int, unordered_map<int, int>> graph;
		for (auto& edge : edges) {
			int u = edge[0], v = edge[1], w = edge[2];
			graph[u][v] = w;
			graph[v][u] = w;
		}
		// Dijkstra 寻找 i~n 的最短路径
		vector<long long> dist(n + 1, INT_MAX);
		dist[n] = 0;
		// 记录已经找到的最短路径的点
		unordered_set<int> visited;
		// 为了避免超时，可以用堆优化
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
		    minHeap;
		minHeap.emplace(0, n);
		while (!minHeap.empty()) {
			auto [min_dist, u] = minHeap.top();
			minHeap.pop();
			visited.insert(u);
			for (auto& [next, w] : graph[u])
				if (visited.count(next) == 0) {
					if (dist[next] > dist[u] + w) {
						dist[next] = dist[u] + w;
						minHeap.emplace(dist[next], next);
					}
				}
		}
		// 记录 i~n 的最短路径数
		vector<long long> dp(n + 1, 0);
		dp[n] = 1;
		vector<long long> order(n);
		iota(order.begin(), order.end(), 1);
		// 按照 dist 从小到大排序
		sort(order.begin(), order.end(), [&](int i, int j) { return dist[i] < dist[j]; });
		for (auto u : order) {
			for (auto& [next, w] : graph[u])
				if (dist[u] > dist[next])
					dp[u] = (dp[u] + dp[next]) % modulo;
			if (u == 1)
				break;
		}

		return dp[1] % modulo;
	}
};
int main() { return 0; }