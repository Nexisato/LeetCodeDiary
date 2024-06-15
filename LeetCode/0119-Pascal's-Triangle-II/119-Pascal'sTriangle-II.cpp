/*
LeeyCode 119: Pascal's Trianlge II
@Description:
Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle
Notice that the row index starts from 0.

Follow Up:
Optimize the algorithm with O(k) extra space

Constraints:
0 <= rowIndex <= 33
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：递归
*/
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res;
		if (rowIndex == 0)
			return {1};
		else if (rowIndex == 1)
			return {1, 1};
		else {
			vector<int> pre = getRow(rowIndex - 1);
			pre.insert(pre.begin(), 0);
			for (int i = 0; i < pre.size() - 1; i++)
				pre[i] = pre[i] + pre[i + 1];
			res = pre;
		}
		return res;
	}
};
/*
思路：线性递推
*/
class Solution_linear {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res(rowIndex + 1, 0);
		res[0] = 1;
		for (int i = 1; i <= rowIndex; ++i)
			res[i] = (long long)res[i - 1] * (rowIndex - i + 1) / i;
		return res;
	}
};
int main() {
	Solution ss;
	int rowIndex = 3;
	vector<int> res = ss.getRow(rowIndex);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << "\t";
	cout << "\n";
	return 0;
}
