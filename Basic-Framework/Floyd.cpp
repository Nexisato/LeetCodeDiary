/*
 * @Date: 2024-02-20 09:01:11
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0000-Basic-Framework/Floyd.cpp
 * @Description:
 */
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Floyd {
public:
	vector<vector<int>> floyd(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<vector<int>> dist(graph);
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		return dist;
	}
};

int main() {
	vector<vector<int>> graph = {
	    {0, 5, INT_MAX, 10}, {INT_MAX, 0, 3, INT_MAX}, {INT_MAX, INT_MAX, 0, 1}, {INT_MAX, INT_MAX, INT_MAX, 0}};
	Floyd floyd;
	vector<vector<int>> res = floyd.floyd(graph);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	return 0;
}