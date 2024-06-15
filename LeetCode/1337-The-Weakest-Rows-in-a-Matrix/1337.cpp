/*
LeetCode 1337: The Weakest Rows in a Matrix
@Description:
You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians).
The soldiers are positioned in front of the civilians.
That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:
- The number of soldiers in row i is less than the number of soldiers in row j.
- Both rows have the same number of soldiers and i < j.

Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

Constraints:
m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] is either 0 or 1.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：二分查找 + 堆
*/
class Solution {
public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		int m = mat.size(), n = mat[0].size();
		vector<pair<int, int>> table;
		for (int i = 0; i < m; ++i) {
			int l = 0, r = n - 1, pos = -1;
			while (l <= r) {
				int mid = l + (r - l) / 2;
				if (mat[i][mid] == 0)
					r = mid - 1;
				else {
					pos = mid;
					l = mid + 1;
				}
			}
			table.emplace_back(pos + 1, i); //最后一个1位置为pos，共pos+1个士兵
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
		for (auto [count, index] : table)
			minHeap.push(pair<int, int>(count, index));

		vector<int> res;
		for (int i = 0; i < k; ++i) {
			res.emplace_back(minHeap.top().second);
			minHeap.pop();
		}

		return res;
	}
};
int main() { return 0; }