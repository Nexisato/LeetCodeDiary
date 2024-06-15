/*
LeetCode: 947 Most Stones Removed from Same Row or Column
Description:
On a 2D plane, we place n stones at some integer coordinate points.
Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone
that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone,
return the largest possible number of stones that can be removed.

Constraints:
1 <= stones.length <= 1000
0 <= xi, yi <= 10^4
No two stones are at the same coordinate point.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：DFS
1. 要移走尽可能多的石头，需要有一个搜索空间，采用DFS
    二维平面视作一个图，石子看作[点]，石子间同行或同列的关系看作[边]
    若两个石子同行或同列，则认为两个石子之间存在一条边
    题目转化为：对于平面图中任何一个点，只要有边与它相连，就把它移除，且要移除尽可能多的点
   *连通图的性质：对于任意一个连通图，总可以通过调整节点的删除顺序，将这个连通图删除到只剩下一个节点（我们不必关心顺序）

*/
class Solution {
public:
	void dfs(int x, vector<vector<int>>& edge, vector<bool>& visited) {
		visited[x] = true;
		for (auto& y : edge[x])
			if (!visited[y])
				dfs(y, edge, visited);
	}
	int removeStones(vector<vector<int>>& stones) {
		int N = stones.size();
		vector<vector<int>> edges(N);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
					edges[i].push_back(j);
		vector<bool> visited(N, false);
		int num = 0;
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				num++;
				dfs(i, edges, visited);
			}
		}
		return N - num;
	}
};
/*
思路：并查集
1. 构造图：只要两个点同行或同列，则将两个点相连接
2. 得到的图：多个连通子图组成的非连通图
3. 对于任何连通图，可以从一端开始不断移除，直到剩下一个点
4. 只需要判断有多少个连通图，最后就剩下多少个点
5. 用节点总数减去连通图的数量即为结果
优化：
    将行和列转化到同一维度
    当遍历到一个点（x,y）时，直接将x与y进行合并，表示该行该列的所有点都属于一个并查集
    用stones的个数减去并查集的个数即可
    x ， y的值有可能冲突，因此将x的值加上10001
*/
class Djset {
public:
	unordered_map<int, int> parent, rank;
	int count;
	Djset(int n) : count(0) {}

	int find(int x) {
		//未加入并查集
		if (parent.find(x) == parent.end()) {
			parent[x] = x;
			count++;
		}
		//路径压缩，父节点作为根节点
		if (x != parent[x]) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	inline void merge(int x, int y) { // y->x; 低秩并到高秩
		int rootx = find(x);
		int rooty = find(y);
		if (rootx != rooty) {
			if (rank[rootx] < rank[rooty])
				swap(rootx, rooty);
			parent[rooty] = rootx;
			if (rootx == rooty)
				rank[rootx] += 1;
			count--;
		}
	}
	int get_count() { return count; }
};
class Solution_uf {
public:
	int removeStones(vector<vector<int>>& stones) {
		int N = stones.size();
		Djset DS(N);
		for (auto& e : stones) {
			DS.merge(e[0] + 10001, e[1]);
		}
		return N - DS.get_count();
	}
};
int main() { return 0; }