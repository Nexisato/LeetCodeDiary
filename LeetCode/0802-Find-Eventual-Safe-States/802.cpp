/*
LeetCode 802: Find Eventual Safe States
@Description:
We start at some node in a directed graph, and every turn, we walk along a directed edge
of the graph. If we reach a terminal node (that is, it has no outgoing directed edges),
we stop.

We define a starting node to be safe if we must eventually walk to a terminal node. More
specifically, there is a natural number k, so that we must have stopped at a terminal
node in less than k steps for any choice of where to walk.

Return an array containing all the safe nodes of the graph. The answer should be sorted
in ascending order.

The directed graph has n nodes with labels from 0 to n - 1, where n is the length of
graph. The graph is given in the following form: graph[i] is a list of labels j such
that (i, j) is a directed edge of the graph, going from node i to node j.

Constraints:
n == graph.length
1 <= n <= 10^4
0 <= graph[i].length <= n
graph[i] is sorted in a strictly increasing order.
The graph may contain self-loops.
The number of edges in the graph will be in the range [1, 4 * 10^4].
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
	/*
	思路：DFS + 三色标记
	根据题意，若起始节点位于一个环内或能到达一个环，节点就是不安全的
	用三色标记法确认环：
	- 白色(0 表示)：节点尚未被访问
	- 灰色(1 表示)：节点位于递归栈中，或在某个环上
	- 黑色(2 表示)：节点搜索完毕，是一个安全节点
	*/
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int> color(n, 0);

		function<bool(int)> safe = [&](int x) {
			if (color[x] > 0)
				return color[x] == 2;
			color[x] = 1;
			//遇到 terminal node 直接跳过循环，返回true
			for (int y : graph[x]) {
				if (!safe(y))
					return false;
			}
			color[x] = 2;
			return true;
		};

		vector<int> res;
		for (int i = 0; i < n; ++i)
			if (safe(i))
				res.emplace_back(i);
		return res;
	}

	vector<int> eventualSafeNodes_Topo(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<vector<int>> invGraph(n);
		vector<int> inDeg(n, 0);

		for (int i = 0; i < n; ++i) {
			for (int x : graph[i])
				invGraph[x].emplace_back(i);
			inDeg[i] = graph[i].size(); //反图即入度
		}

		queue<int> q;
		for (int i = 0; i < n; ++i)
			if (inDeg[i] == 0)
				q.push(i);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int x : invGraph[cur]) {
				--inDeg[x];
				if (inDeg[x] == 0)
					q.push(x);
			}
		}
		//原图中最终入度为0的均为安全点
		vector<int> res;
		for (int i = 0; i < n; ++i)
			if (inDeg[i] == 0)
				res.emplace_back(i);
		return res;
	}
};
int main() { return 0; }