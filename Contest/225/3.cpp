/*
5663. 找出第 K 大的异或坐标值

给你一个二维矩阵 matrix 和一个整数 k ，矩阵大小为 m x n 由非负整数组成。
矩阵中坐标 (a, b) 的 值 可由对所有满足 0 <= i <= a < m 且 0 <= j <= b < n 的元素
matrix[i][j] （下标从 0 开始计数）执行异或运算得到。

请你找出 matrix 的所有坐标中第 k 大的值（k 的值从 1 开始计数)
提示：
m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
0 <= matrix[i][j] <= 10^6
1 <= k <= m * n
*/
#include <bits/stdc++.h>
using namespace std;

/*
思路：
1. 对于matrix矩阵，新建一个等大小的异或值矩阵value
2. 令value[i][j] =
matrix[i][j]，value对于左、上、左上三个方向上的节点值都要进行异或运算（注意好边界判定条件）
3. 用一个res数组记录所有坐标位置的异或值，第 k 大的元素即为 顺序遍历第 res.size() - k
个元素
*/
class Solution {
public:
	int KthLargestValue(vector<vector<int>>& matrix, int k) {
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> value(m, vector<int>(n));
		vector<int> res;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				value[i][j] = matrix[i][j];
				if (i - 1 >= 0 && j - 1 >= 0)
					value[i][j] ^= value[i - 1][j - 1];
				if (i - 1 >= 0)
					value[i][j] ^= value[i - 1][j];
				if (j - 1 >= 0)
					value[i][j] ^= value[i][j - 1];
				res.push_back(value[i][j]);
			}
		nth_element(res.begin(), res.begin() + res.size() - k, res.end());
		return res[res.size() - k]; //第k大即为顺序第N-k个元素
	}
};

int main() {
	Solution ss;
	vector<vector<int>> matrix{{10, 9, 5}, {2, 0, 4}, {1, 0, 9}, {3, 4, 8}};
	vector<vector<int>> tmp{{5, 2}, {1, 6}};
	int K = 3;
	cout << ss.KthLargestValue(tmp, K);

	return 0;
}