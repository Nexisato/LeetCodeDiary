#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

/**
 * 思路:
 * 从左上角到右下角，找到一条路径，使得路径上相邻两点的高度差的绝对值最小
 *  使用并查集，若两个相邻顶点之间存在差距，则视为一条边，权值为两点之间的高度差
 *  先构造边的数据结构，存储 x, y, z，分别代表两个顶点的坐标和权值（高度差）
 *  再构造并查集，将所有边按照权值从小到大排序，依次合并两个顶点，直到左上角和右下角的顶点连通
 */

class UnionFind {
private:
	vector<int> parent;
	vector<int> rank;
	int count;
	int n;

public:
	UnionFind(int _n)
	    : parent(vector<int>(_n)), rank(vector<int>(_n, 1)), count(_n), n(_n) {
		iota(parent.begin(), parent.end(), 0);
	}

	int find(int x) { return x == parent[x] ? x : (parent[x] = find(parent[x])); }
	void merge(int x, int y) {
		int rootx = find(x), rooty = find(y);
		if (rootx != rooty) {
			if (rank[rootx] <= rank[rooty]) {
				swap(rootx, rooty);
			}
			parent[rooty] = rootx;
			rank[rootx] += rank[rooty];
			--count;
		}
	}
	bool isConnected(int i, int j) { return find(i) == find(j); }
};

// 边 - 数据结构
struct Edge {
	int x, y, z;
	Edge(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
	// 重载小于号，用于排序, const 修饰函数，表示该函数不会修改成员变量
	bool operator<(const Edge& that) const { return z < that.z; }
};

class Solution {
public:
	int minimumEffortPath(vector<vector<int>>& heights) {
		int res = 0;
		const int rows = heights.size();
		const int cols = heights[0].size();
		vector<Edge> edges;

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				int idx = i * cols + j;
				// 水平方向的边
				if (j > 0) {
					edges.emplace_back(idx - 1, idx,
					                   abs(heights[i][j] - heights[i][j - 1]));
				}
				// 垂直方向的边
				if (i > 0) {
					edges.emplace_back(idx - cols, idx,
					                   abs(heights[i][j] - heights[i - 1][j]));
				}
			}
		}
		// 按照边的大小排序
		sort(edges.begin(), edges.end());
		UnionFind uf_set(rows * cols);
		for (const auto& edge : edges) {
			uf_set.merge(edge.x, edge.y);
			if (uf_set.isConnected(0, rows * cols - 1)) {
				res = edge.z;
				break;
			}
		}
		return res;
	}
};

int main() {
	Solution ss;

	return 0;
}
