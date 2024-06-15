/*
LCOffer: 二维数组中的查找
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

限制：
0 <= n <= 1000
0 <= m <= 1000
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0)
			return false;
		int n = matrix.size(), m = matrix[0].size();
	}
};
int main() {
	vector<vector<int>> matrix{{-1, 3}};
	int target = 3;
	Solution* ss = new Solution();
	bool flag = ss->findNumberIn2DArray(matrix, target);
	cout << flag << endl;
	return 0;
}