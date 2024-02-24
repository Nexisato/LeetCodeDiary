#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 因为是稀疏的阻塞，所以可以用双向的 BFS，加上 visited 的限制，来判断是否能逃脱
 */
class Solution {
private:
	const int N = 1e6;
    const int MAX_BLOCKED = 200 * 200;
	long long hash(int x, int y) { return (long long)x * N + y; }
	pair<int, int> unhash(long long h) { return make_pair(h / N, h % N); }

public:
	bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
		const int N = 1e6;
		if (blocked.size() < 2)
			return true;
		unordered_set<long long> st;
		for (auto& b : blocked) {
			st.insert(hash(b[0], b[1]));
		}

		int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

		auto bfs = [&](const vector<int>& src, const vector<int>& dst) -> bool {
			queue<pair<int, int>> q;
			unordered_set<long long> visited;
			q.push(make_pair(src[0], src[1]));
			while (!q.empty()) {
				auto [x, y] = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i) {
					int nx = x + dir[i][0];
					int ny = y + dir[i][1];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N || 
                        st.count(hash(nx, ny)) 
                        || visited.count(hash(nx, ny)))
						continue;
					if (nx == dst[0] && ny == dst[1])
						return true;
                    visited.insert(hash(nx, ny));
                    q.push(make_pair(nx, ny));
				}
                if (visited.size() >= MAX_BLOCKED) return true;
			}
			return false;
		};
		return bfs(source, target) && bfs(target, source);
	}
};
int main() { return 0; }