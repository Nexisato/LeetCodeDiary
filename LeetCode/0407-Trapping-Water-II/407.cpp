/*
 * @Date: 2024-01-28 17:33:26
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0407-Trapping-Water-II/407.cpp
 * @Description:
 */
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
/**
 *  3D 接雨水
 * 找到一个点，它的高度是它周围最低的
 * 堆优化的 Dijkstra
 */
class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		const int m = heightMap.size();
		const int n = heightMap[0].size();
		int res = 0;
		unordered_set<int> visited; // i * n + j
		// 高度，坐标
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
		               greater<pair<int, pair<int, int>>>>
		    minHeap;
		// 将四周的点加入堆
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
					minHeap.push({heightMap[i][j], {i, j}});
					visited.insert(i * n + j);
				}
		int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		while (!minHeap.empty()) {
			auto [h, xy] = minHeap.top();
			int x = xy.first, y = xy.second;
			minHeap.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = x + dir[i][0], ny = y + dir[i][1];
				if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited.count(nx * n + ny))
					continue;
				visited.insert(nx * n + ny);
				if (heightMap[nx][ny] < h)
					res += h - heightMap[nx][ny];
				minHeap.push({max(h, heightMap[nx][ny]), {nx, ny}});
			}
		}
		return res;
	}
};
int main() { return 0; }