#include <bits/stdc++.h>
using namespace std;
/**
 *
 */
class Solution {
	// private:
	//     void dfs(const int& node, const vector<vector<int>>& gardens, vector<int>& visited) {
	//         if (visited[node] == 0) {
	//             set<int> flower({1, 2, 3, 4});
	//             vector<int> links;
	//             for (int j = 0; j < gardens[node].size(); ++j) {
	//                 if (gardens[node][j] == 0) continue;
	//                 if (visited[j] != 0) {
	//                     flower.erase(visited[j]);
	//                 } else {
	//                     links.push_back(j);
	//                 }
	//             }
	//             for (set<int>::iterator it = flower.begin(); it != flower.end(); ++it) {
	//                 visited[node] = *it;
	//                 break;
	//             }
	//             for (const auto& link : links) {
	//                 dfs(link, gardens, visited);
	//             }
	//         }
	//         return;
	//     }
	// public:
	//     vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
	//         vector<int> flower(n, 0);
	//         vector<vector<int>> gardens(n, vector<int>(n, 0));
	//         for (const auto& path: paths) {
	//             int x = path[0] - 1, y = path[1] - 1;
	//             gardens[x][y] = 1;
	//             gardens[y][x] = 1;
	//         }
	//         for (int i = 0; i < n; ++i)
	//             dfs(i, gardens, flower);
	//         return flower;
	//     }
public:
	vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
		vector<int> flower(n, 0);
		vector<vector<int>> gardens(n);
		for (const auto& path : paths) {
			int x = path[0] - 1, y = path[1] - 1;
			gardens[x].push_back(y);
			gardens[y].push_back(x);
		}
		for (int i = 0; i < n; ++i) {
			vector<bool> colored(5, false);
			for (auto& vertex : gardens[i]) {
				colored[flower[vertex]] = true; //先标记 gardens[i] 的邻接点 vertex 用flower[vertex]标记为 colored
			}
			for (int j = 1; j <= 4; ++j) {
				if (colored[j] == 0) {
					flower[i] = j;
					break;
				}
			}
		}

		return flower;
	}
};
int main() { return 0; }