/*
LeetCode 847: Shortes Path Visiting All Rooms
@Description:
You have an undirected, connected graph of n nodes labeled from 0 to n - 1.
You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit
nodes multiple times, and you may reuse edges.

Constraints:
n == graph.length
1 <= n <= 12
0 <= graph[i].length < n
graph[i] does not contain i.
If graph[a] contains b, then graph[b] contains a.
The input graph is always connected.
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

class Solution {
public:
	/*
	思路：状态压缩 + BFS
	1. 定义变量 state ，低 n 位表示这些点是否被访问过，设点 x
	    a = (state >> x) & 1； 确定是否被访问
	    state = state | (1 << x); x已被访问并更新状态
	*/
	int shortestPathLength(vector<vector<int>>& graph) {
		const int INF = 0x3f3f3f3f;
		int n = graph.size();
		int mask = 1 << n;
		// mask 表示访问的状态总数
		int dist[mask][n];
		memset(dist, INF, sizeof(dist));

		// BFS 先将起始状态入队
		queue<pair<int, int>> q;
		for (int i = 0; i < n; ++i) {
			dist[1 << i][i] = 0;
			q.emplace(1 << i, i);
		}

		while (!q.empty()) {
			auto [state, node] = q.front();
			int step = dist[state][node];
			q.pop();
			if (state == (mask - 1))
				return step;
			for (int i : graph[node]) {
				int v = state | (1 << i);
				if (dist[v][i] == INF) {
					dist[v][i] = step + 1;
					q.emplace(v, i);
				}
			}
		}

		return -1;
	}
};
int main() {
	vector<vector<int>> graph({{1, 2, 3}, {0}, {0}, {0}});
	Solution* ss = new Solution();
	int res = ss->shortestPathLength(graph);
	cout << res << endl;

	return 0;
}