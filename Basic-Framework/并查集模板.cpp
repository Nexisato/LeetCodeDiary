#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
const int MAXN = 999;

// 1. 初始化 & 查询
int fa[MAXN];
inline void init(int n) {
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
}

int find(int x) {
	if (fa[x] == x)
		return x;
	else
		return find(fa[x]);
}

inline void merge(int i, int j) { fa[find(i)] = find(j); }

// 2. 路径压缩
// 将沿途的每个节点的父节点都设为根节点
int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }

// 3. 按秩压缩 （可能带来额外的空间复杂度）

int rank[MAXN] = {0};
inline void init(int n) {
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
		rank[i] = 1;
	}
}
inline void merge(int i, int j) {
	int x = find(i), y = find(j);
	if (rank[x] <= rank[y])
		fa[x] = y;
	else
		fa[y] = x;
	if (rank[x] == rank[y] && x != y)
		rank[y]++;
}

// 查询两点是否同根
bool isSame(int i, int j) { return find(i) == find(j); }

// 常规
class UnionFind {
private:
	vector<int> parent;
	vector<int> rank;
	int count;
	int n;

public:
	UnionFind(int _n) : parent(vector<int>(_n)), rank(vector<int>(_n, 1)), count(_n), n(_n) {
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