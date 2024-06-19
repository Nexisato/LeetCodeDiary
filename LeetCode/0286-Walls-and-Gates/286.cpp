/*
LeetCode 286: Walls and Gates
@Description:
You are given an m x n grid rooms initialized with these three possible values.

· -1 A wall or an obstacle.
· 0 A gate.
· INF Infinity means an empty room.

We use the value 2^31 - 1 = 2147483647 to represent INF
as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach
a gate, it should be filled with INF.

Constraints:
m == rooms.length
n == rooms[i].length
1 <= m, n <= 250
rooms[i][j] is -1, 0, or 2^31 - 1.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
*/
class Solution {
public:
	void wallsAndGates(vector<vector<int>>& rooms) {
		const int INF = INT32_MAX;
		int m = rooms.size(), n = rooms[0].size();

		/*Queue记录gate的 row col flag*/
		/*
		由于我们将gate先入队，因此对于不同gate可以同时到达的空房间
		    如果先BFS遍历到，表明这个空房间到相应的gate是最短的，因此无需进一步更新距离
		*/
		queue<tuple<int, int, int>> q;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (rooms[i][j] == 0) {
					q.push(tuple<int, int, int>(i, j, 0));
					// q.emplace(i, j, 0);
				}

		while (!q.empty()) {
			auto [r, c, dist] = q.front();
			q.pop();
			// gate为源，BFS搜索四周每个空房间
			for (auto [dr, dc] :
			     vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
				int nr = r + dr;
				int nc = c + dc;
				if (nr >= 0 && nr < m && nc >= 0 && nc < n && rooms[nr][nc] == INF) {
					rooms[nr][nc] = dist + 1;
					q.emplace(nr, nc, dist + 1);
				}
			}
		}
	}
};
int main() { return 0; }