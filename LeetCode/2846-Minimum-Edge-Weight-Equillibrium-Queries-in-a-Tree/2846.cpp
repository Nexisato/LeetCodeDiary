/*
 * @Date: 2024-01-26 16:36:48
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2846-Minimum-Edge-Weight-Equillibrium-Queries-in-a-Tree/2846.cpp
 * @Description:
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 【LCA】倍增，看不懂，明天看
// 实际上等于这两点之间的边长度，减去这两点之间的出现最多的边的次数
// 求两点间的路径长度，可以通过倍增法求 LCA 来实现。
// 记两点分别为 u, v，最近的公共祖先为 x，u 到 v 长度就是 depth[u] + depth[v] - 2 * depth[x]
// 额外引入一个数组 count[n][26]，用于记录根节点 到 各点 之间每种边出现的次数
class Solution {
public:
	vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
		unordered_map<int, unordered_map<int, int>> graph;
		for (auto& edge : edges) {
			int u = edge[0], v = edge[1], w = edge[2] - 1;
			graph[u][v] = w;
			graph[v][u] = w;
		}
		int m = 32 - __builtin_clz(n);
		vector<vector<int>> pa(n, vector<int>(m, -1));
		vector<vector<array<int, 26>>> cnt(n, vector<array<int, 26>>(m));
		vector<int> depth(n, 0);

		// 获得深度和父节点
		// 默认 0 号节点为根节点
		function<void(int, int)> dfs = [&](int node, int fa) {
			pa[node][0] = fa;
			for (auto& [next, w] : graph[node]) {
				if (next != fa) {
					cnt[next][0][w] = 1;
					depth[next] = depth[node] + 1;
					dfs(next, node);
				}
			}
		};
		dfs(0, -1);

		for (int i = 0; i < m - 1; ++i) {
			for (int x = 0; x < n; ++x) {
				int pp = pa[x][i];
				if (pp != -1) {
					pa[x][i + 1] = pa[pp][i];
					// 注意这里状态转移的意义
					// x 到第 2^i + 1第j个权重的个数等于什么
					for (int j = 0; j < 26; ++j)
						cnt[x][i + 1][j] = cnt[x][i][j] + cnt[pp][i][j];
				}
			}
		}

		auto get_lca = [&](int x, int y, vector<int>& cw) -> int {
			if (depth[x] > depth[y])
				swap(x, y);
			// 使 x, y 处于同一深度
			for (int d = depth[y] - depth[x]; d; d &= d - 1) {
				int tmp = __builtin_ctz(d);
				int next = pa[y][tmp];
				for (int j = 0; j < 26; ++j) {
					// 此时更新一下路径上 j 权重的数目
					cw[j] += cnt[y][tmp][j];
				}
				y = next;
			}
			if (x == y)
				return x;
			for (int i = m - 1; i >= 0; --i) {
				int px = pa[x][i], py = pa[y][i];
				if (px != py) {
					for (int j = 0; j < 26; ++j)
						cw[j] += cnt[x][i][j] + cnt[y][i][j];
					x = px;
					y = py;
				}
			}
			for (int j = 0; j < 26; ++j)
				cw[j] += cnt[x][0][j] + cnt[y][0][j];
			return pa[x][0];
		};

		vector<int> ans;
		vector<int> cw(26);
		for (auto& query : queries) {
			int x = query[0], y = query[1];
			fill(cw.begin(), cw.end(), 0);
			int res = depth[x] + depth[y];

			int lca = get_lca(x, y, cw);

			res -= 2 * depth[lca];
			res -= (*max_element(cw.begin(), cw.end()));
			ans.push_back(res);
		}
		return ans;
	}
};
int main() { return 0; }