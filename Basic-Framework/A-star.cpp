/*
 * @Date: 2024-02-24 11:43:14
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0000-Basic-Framework/A-star.cpp
 * @Description:

A*算法
 */
#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

const long long N = 1e6;

long long ord_hash(int x, int y) { return (long long)x * N + y; }
pair<int, int> ord_unhash(long long h) { return make_pair(h / N, h % N); }

int heuristic(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int aStarSearch(vector<vector<int>>& graph, pair<int, int> start, pair<int, int> end) {
	int m = graph.size();
	int n = graph[0].size();
	set<long long> visited;
	// f = g + h
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
	               greater<pair<int, pair<int, int>>>>
	    pq;
	pq.push({0, start});
	while (!pq.empty()) {
		auto [f, cur] = pq.top();
		pq.pop();
		int x = cur.first, y = cur.second;
		long long xy = ord_hash(x, y);
		if (visited.count(xy))
			continue;
		visited.insert(xy);
		if (cur == end)
			return f;
		for (int i = 0; i < 4; ++i) {
			int nx = cur.first + dir[i][0];
			int ny = cur.second + dir[i][1];
			long long nxy = ord_hash(nx, ny);
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || graph[nx][ny] == 1 ||
			    visited.count(nxy))
				continue;
			int g = f + 1;
			int h = heuristic({nx, ny}, end);
			pq.push({g + h, {nx, ny}});
		}
	}
	return -1;
}

int main() { return 0; }