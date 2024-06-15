/*
 * @Date: 2024-01-27 16:27:17
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/1483-Get-Kth-Ancestor/1483.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 【LCA】倍增法求 LCA
// 其实就是二进制拆分，非常巧妙的方法
class TreeAncestor {
private:
	vector<vector<int>> fn;

public:
	TreeAncestor(int n, vector<int>& parent) {
		int m = 32 - __builtin_clz(n);
		fn.resize(n, vector<int>(m, -1));
		// 先枚举 m 列，再枚举 n 行
		for (int i = 0; i < n; ++i)
			fn[i][0] = parent[i];
		for (int i = 0; i < m - 1; ++i)
			for (int x = 0; x < n; ++x) {
				if (fn[x][i] != -1)
					fn[x][i + 1] = fn[fn[x][i]][i];
			}
	}
	int getKthAncestor(int node, int k) {
		// 这里算二进制位就好
		int m = 32 - __builtin_clz(k);
		for (int i = 0; i < m; ++i) {
			if ((k >> i) & 1) {
				node = fn[node][i];
				if (node < 0)
					break;
			}
		}
		return node;
	}
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
int main() { return 0; }