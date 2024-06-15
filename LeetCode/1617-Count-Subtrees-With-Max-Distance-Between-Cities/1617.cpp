#include <bits/stdc++.h>
using namespace std;

/*
直接 DFS，找树的直径
*/
class Solution {
public:
	vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
		vector<int> res(n - 1, 0);
		vector<vector<int>> adj(n); // 邻接表
		for (auto& e : edges) {
			int u = e[0] - 1, v = e[1] - 1;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}

		int next = 0, msk = 0, maxDepth = 0;
		function<void(int, int)> dfs = [&](int u, int d) {
			msk ^= 1 << u; // 这里 异或 后 对应第 u 位 msk 为0，代表节点 u 访问过，否则 1 表示未访问过
			if (maxDepth < d) {
				maxDepth = d;
				next = u;
			}
			for (int& v : adj[u])
				if (msk >> v & 1) // 判断 v 是否出现过，前面的掩码都是 0
					dfs(v, d + 1);
		};

		for (int mask = 1; mask < 1 << n; mask++) {
			if ((mask & (mask - 1)) == 0) //判断是否为 2 的幂次，即若只有 1 个节点的子树，跳过，注意运算优先级
				continue;
			msk = mask;
			maxDepth = 0;
			int cur = 31 - __builtin_clz(msk); //计算前面有多少个0，也即 cur 代表 msk 最高位所在的位置
			dfs(cur, 0);
			if (msk == 0) {
				msk = mask;
				maxDepth = 0;
				dfs(next, 0);
				res[maxDepth - 1]++;
			}
		}
		return res;
	}
};
int main() { return 0; }