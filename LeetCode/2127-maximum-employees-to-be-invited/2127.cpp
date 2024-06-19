#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * @brief
 * 构建 基环内向树
 * 比较： 最大环长度 和 长度为2的环加上最长链
 * 取二者的最大值即可
 */
class Solution {
public:
	int maximumInvitations(vector<int>& favorite) {
		return max(maxCycle(favorite), topoSortCycle(favorite));
	}
	// DFS 寻找最长环
	int maxCycle(const vector<int>& favorite) {
		int res = 0;
		const int n = favorite.size();
		vector<bool> visited(n, false);
		for (int i = 0; i < n; ++i) {
			if (visited[i])
				continue;
			int cur = i;
			vector<int> cycle;
			while (!visited[cur]) {
				visited[cur] = true;
				cycle.push_back(cur);
				cur = favorite[cur];
			}
			for (int j = 0; j < cycle.size(); ++j) {
				if (cycle[j] == cur) {
					res = max(res, (int)cycle.size() - j);
					break;
				}
			}
		}
		return res;
	}

	// 拓扑排序寻找DAG最长链
	int topoSortCycle(const vector<int>& favorite) {
		int res = 0;
		const int n = favorite.size();
		vector<int> indeg(n);
		vector<int> dist(n, 1); // 每个节点都有一个出度
		for (const auto& v : favorite)
			++indeg[v];

		queue<int> q;
		for (int i = 0; i < n; ++i)
			if (indeg[i] == 0)
				q.push(i);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			dist[favorite[cur]] = max(dist[favorite[cur]], dist[cur] + 1);
			if (--indeg[favorite[cur]] == 0)
				q.push(favorite[cur]);
		}
		for (int i = 0; i < n; ++i)
			if (i == favorite[favorite[i]])
				res += dist[i];
		return res;
	}
};
int main() { return 0; }