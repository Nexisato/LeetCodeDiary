/*
 * @Date: 2024-02-19 22:54:57
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0000-Basic-Framework/Kruskal.cpp
 * @Description: 基于并查集 实现Kruskal算法，适合边稠密的图
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
class UF {
private:
	vector<int> parent;
	vector<int> rank;

public:
	int capacity;
	int count;
	UF(int cap) : parent(cap), rank(cap, 0), capacity(cap), count(0) {
		iota(parent.begin(), parent.end(), 0);
	}
	int find(int x) {
		while (x != parent[x]) {
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}
	bool isConnected(int x, int y) { return find(x) == find(y); }
	void merge(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		if (rootX != rootY) {
			if (rank[rootX] <= rank[rootY]) {
				swap(rootX, rootY);
			}
			parent[rootY] = rootX;
			rank[rootX] += (rank[rootY] == rank[rootX]);
			++count;
		}
	}
};
struct Edge {
	int from;
	int to;
	int weight;
	Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
	bool operator<(const Edge& other) const { return weight < other.weight; }
	bool operator>(const Edge& other) const { return weight > other.weight; }
};
/**
 * Kruskal算法
 * 贪心算法，每次选择权重最小的边，如果不构成环，就加入到最小生成树中
 */
int kruskal(vector<vector<int>>& graph) {
	const int n = graph.size();
	UF uf(n);
	vector<Edge> edges;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (graph[i][j] != INT_MAX) {
				edges.emplace_back(i, j, graph[i][j]);
			}
		}
	}
	sort(edges.begin(), edges.end());
	int res = 0;
	for (const auto& e : edges) {
		if (!uf.isConnected(e.from, e.to)) {
			uf.merge(e.from, e.to);
			res += e.weight;
		}
	}
	return uf.count == n - 1 ? res : -1;
}
int main() {
	vector<vector<int>> graph = {{0, 2, 4, 1, INT_MAX},
	                             {2, 0, INT_MAX, 3, INT_MAX},
	                             {4, INT_MAX, 0, INT_MAX, 3},
	                             {1, 3, INT_MAX, 0, 4},
	                             {INT_MAX, INT_MAX, 3, 4, 0}};
	int res = kruskal(graph);
	cout << res << endl;
	return 0;
}