#include <bits/stdc++.h>
using namespace std;
/**
 * @brief
 * 对于 matrix 每一个位置 matrix[i][j]，0 <= i < m, 0 <= j < n，matrix[i][j] = min(rowSum[i], colSum[j])
 * 遍历完成后即为答案.
 * 贪心解法
 */
class Solution {

public:
	vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
		int m = rowSum.size(), n = colSum.size();
		vector<vector<int>> res(m, vector<int>(n, 0));
		int i = 0, j = 0;
		while (i < m && j < n) {
			int threshold = min(rowSum[i], colSum[j]);
			res[i][j] = threshold;
			rowSum[i] -= threshold;
			colSum[j] -= threshold;
			if (rowSum[i] == 0)
				i++;
			if (colSum[j] == 0)
				j++;
		}
		return res;
	}
};
int main() { return 0; }