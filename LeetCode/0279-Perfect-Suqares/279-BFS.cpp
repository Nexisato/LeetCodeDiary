/*
LeetCode 279: Perfect Squares
@Description:
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words,
it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Constraints:
1 <= n <= 10^4
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：BFS
*/
class Solution {
public:
	int numSquares(int n) {
		int tmp = (int)sqrt(n);
		if (tmp * tmp == n)
			return 1;
		queue<int> q;
		q.push(0);
		vector<bool> visited(n, 0);
		int count = 0;
		while (!q.empty()) {
			int size = q.size();
			++count;
			for (int i = 0; i < size; ++i) {
				int cur = q.front();
				q.pop();
				for (int j = 1; j <= tmp; ++j) {
					int num = cur + j * j;
					if (num == n)
						return count;
					if (num > n)
						break;
					if (!visited[num]) {
						q.push(num);
						visited[num] = true;
					}
				}
			}
		}
		return n;
	}
};
int main() { return 0; }