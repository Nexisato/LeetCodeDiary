/*
LeetCode 200: Number of Islands
@Description:
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路: 并查集
*/
class UnionFind {
private:
	vector<int> parent;
	vector<int> rank;
	int count;

public:
	/*
	UnionFind(int n): parent(vector<int>(n)), rank(vector<int>(n)), count(0){
	    for (int i = 0; i < n; ++i)
	        parent[i] = i;
	}
	*/
	//并查集并非直接改模板即可直接套用，需要根据实际情况，对构造函数做进一步的修改
	//初始化 m * n个节点
	UnionFind(vector<vector<char>>& grid) {
		parent.clear();
		rank.clear();
		count = 0;
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '1') {
					parent.emplace_back(i * n + j);
					++count;
				} else
					parent.emplace_back(-1);
				rank.push_back(0);
			}
	}

	int find(int x) {
		if (x != parent[x])
			parent[x] = find(parent[x]);
		return parent[x];
	}

	void merge(int x, int y) {
		int rootx = find(x);
		int rooty = find(y);
		if (rootx != rooty) {
			if (rank[rootx] < rank[rooty])
				swap(rootx, rooty);
			parent[rooty] = rootx; // high rank node is the parent of low rank node
			if (rank[rootx] == rank[rooty])
				rank[rootx] += 1;
			--count;
		}
	}

	int get_count() const { return count; }

	bool isMerged(int x, int y) { return (find(x) == find(y)); }
};

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int m = grid.size(), n = grid[0].size();
		int res = 0;
		UnionFind uf(grid);

		int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '1') {
					grid[i][j] = '0';
					for (int k = 0; k < 4; ++k) {
						int nx = i + d[k][0];
						int ny = j + d[k][1];
						if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1')
							uf.merge(i * n + j, nx * n + ny);
					}
				}
			}

		return uf.get_count();
	}
};

int main() { return 0; }