/*
LeetCode 554: Brick Wall
@Description:
There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of
the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.

Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a
brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of
the wall, in which case the line will obviously cross no bricks.

Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks
after drawing such a vertical line.

Constraints:
n == wall.length
1 <= n <= 10^4
1 <= wall[i].length <= 10^4
1 <= sum(wall[i].length) <= 2 * 10^4
sum(wall[i]) is the same for each row i.
1 <= wall[i][j] <= 2^31 - 1
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：哈希表
问题转化为n行墙最多多少个相同的前缀和
*/
class Solution {
public:
	int leastBricks(vector<vector<int>>& wall) {
		int n = wall.size();
		int width = accumulate(wall[0].begin(), wall[0].end(), 0);
		// n行墙最多多少个相同前缀和
		int maxCountPrefix = 0;
		unordered_map<int, int> table;
		for (int i = 0; i < n; ++i) {
			vector<int> tmp = wall[i];
			int L = tmp.size();
			int prefix = 0;
			//此处不能遍历到结尾
			for (int j = 0; j < L - 1; ++j) {
				prefix += tmp[j];
				++table[prefix];
			}
		}
		for (auto& item : table)
			maxCountPrefix = max(item.second, maxCountPrefix);
		return n - maxCountPrefix;
	}
};
int main() {
	vector<vector<int>> wall;
	Solution ss;

	return 0;
}