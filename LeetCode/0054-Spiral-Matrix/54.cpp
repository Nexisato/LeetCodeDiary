/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0054-Spiral-Matrix/54.cpp
 * @Description:
 */
/*
LeetCode 54: Spiral Matrix
@Description:
Given an m x n matrix, return all elements of the matrix in spiral order.

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/
#include <iostream>
#include <vector>
using namespace std;
/*
思路：直接模拟
*/
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int m = matrix.size(), n = matrix[0].size();
		if (m == 0 || n == 0)
			return {};
		int l = 0, r = n - 1, up = 0, down = m - 1;
		while (l <= r && up <= down) {
			for (int j = l; j <= r; ++j)
				res.emplace_back(matrix[up][j]);
			for (int i = up + 1; i <= down; ++i)
				res.emplace_back(matrix[i][r]);
			// 确保不会重复添加
			if (l < r && up < down) { // ensure no extra element in vector arr
				for (int j = r - 1; j >= l; --j)
					res.emplace_back(matrix[down][j]);
				for (int i = down - 1; i > up; --i)
					res.emplace_back(matrix[i][l]);
			}
			l++;
			r--;
			up++;
			down--;
		}
		return res;
	}
};
int main() {
	Solution ss;
	vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	vector<int> res = ss.spiralOrder(matrix);
	for (auto it = res.begin(); it != res.end(); ++it)
		cout << *(it) << "  ";
	cout << "\n";
	return 0;
}