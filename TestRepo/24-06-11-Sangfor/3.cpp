/**
 * Floyd 模板题
 * 输入为 ip 地址 和 对应的节点编号
 */
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	unordered_map<string, int> table;
	for (int i = 0; i < n; ++i) {
		string cur_ip;
		int cur_val;
		cin >> cur_ip >> cur_val;
		table[cur_ip] = cur_val;
	}

	// 输入边关系
	vector<vector<int>> graph(n, vector<int>(n, INT32_MAX));
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int node1, node2;
		cin >> node1 >> node2;
		graph[node1][node2] = graph[node2][node1] = 1;
	}

	// Floyd process
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (graph[i][k] != INT32_MAX && graph[k][j] != INT32_MAX) {
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string ip1, ip2;
		cin >> ip1 >> ip2;
		int node1 = table[ip1], node2 = table[ip2];
		if (graph[node1][node2] == INT32_MAX) {
			cout << -1 << endl;
		} else {
			cout << graph[node1][node2] << endl;
		}
	}

	return 0;
}