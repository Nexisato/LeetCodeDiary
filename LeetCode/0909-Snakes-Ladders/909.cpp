/*
 * @Date: 2024-01-10 12:49:14
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0909_Snakes_Ladders/909.cpp
 * @Description:
 */
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int snakesAndLadders(vector<vector<int>>& board) {
		const int n = board.size();
		int start = 1, target = n * n;

		auto getPos = [](int id, int n) -> pair<int, int> {
			int r = (id - 1) / n, c = (id - 1) % n;
			if (r % 2 == 1) {
				c = n - 1 - c;
			}
			// 这里行转换一定要最后做
			r = n - 1 - r;
			return make_pair(r, c);
		};

		// 为了找到最小，队列可以记录当前的 idx 和 对应的步长，而非只有 idx
		queue<pair<int, int>> q;
		q.push({start, 0});
		vector<bool> visisted(n * n + 1, false);
		visisted[start] = true;
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			for (int i = 1; i <= 6; ++i) {
				int next = cur.first + i;
				if (next > n * n)
					break;
				auto [r, c] = getPos(next, n);
				if (board[r][c] > 0) {
					next = board[r][c];
				}
				if (next == target) {
					return cur.second + 1;
				}
				if (!visisted[next]) {
					q.push({next, cur.second + 1});
					visisted[next] = true;
				}
			}
		}
		return -1;
	}
};
int main() { return 0; }