#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// -1 障碍，0 垃圾 1 小区 2 空白
int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> graph(m, vector<int>(n, -1));
	vector<vector<int>> dis(m, vector<int>(n, INT32_MAX));
	queue<pair<int, int>> q;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> graph[i][j];
			if (graph[i][j] == 0) {
				dis[i][j] = 0;
				q.push({i, j});
			}
		}
    }
	int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dir[i][0], ny = y + dir[i][1];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || graph[nx][ny] == -1 ||
			    dis[nx][ny] != INT32_MAX)
				continue;
			dis[nx][ny] = dis[x][y] + 1;
			q.push({nx, ny});
		}
	}
	int res = 0;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (graph[i][j] == 1 && dis[i][j] != INT32_MAX)
				res += dis[i][j];

	cout << res << endl;

	return 0;
}