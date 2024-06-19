/*
LeetCode 743: Network Delay Time
@Description:
You are given a network of n nodes, labeled from 1 to n. You are also given times, a
list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source
node, vi is the target node, and wi is the time it takes for a signal to travel from
source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes
to receive the signal. If it is impossible for all the n nodes to receive the signal,
return -1.

Constraints:
1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/
#include <algorithm>
#include <iostream>
#include <vector>
/*
思路：Dijkstra
注意不要忽略掉used数组
*/
class Solution {
public:
	int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
		const int INF = 1e+9;
		std::vector<std::vector<int>> edges(n + 1, std::vector<int>(n + 1, INF));
		for (int i = 0; i <= n; ++i)
			edges[i][i] = 0;
		int length = times.size();
		for (int i = 0; i < length; ++i) {
			int source = times[i][0], dest = times[i][1], cost = times[i][2];
			edges[source][dest] = cost;
		}
		std::vector<int> paths(n + 1, INF);
		for (int i = 0; i <= n; ++i)
			paths[i] = edges[k][i];
		std::vector<bool> used(n + 1, false); //用于确定是否更新到最短路
		for (int i = 1; i <= n; ++i) {
			int x = 0;
			for (int y = 1; y <= n; ++y) {
				if (!used[y] && (x == 0 || paths[y] < paths[x]))
					x = y;
			}
			used[x] = true;
			for (int d = 1; d <= n; ++d) {
				int tmpL = paths[x] + edges[x][d];
				paths[d] = std::min(paths[d], tmpL);
			}
		}
		int maxElem = *std::max_element(paths.begin() + 1, paths.end());
		int res = (maxElem != INF) ? maxElem : -1;
		return res;
	}
};
int main() {
	std::vector<std::vector<int>> times{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
	int n = 4, k = 2;
	Solution* ss = new Solution();
	int res = ss->networkDelayTime(times, n, k);
	std::cout << res << std::endl;

	return 0;
}