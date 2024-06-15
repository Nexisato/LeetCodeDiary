/*
LeetCode: 118 Pascal's Triangles
Description:
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
不用考虑递归，直接操纵二维向量vector
*/
class Solution {
public:
	vector<int> binomialCoef(int n) {
		if (n <= 0)
			return {};
		else if (n == 1)
			return {1};
		else if (n == 2)
			return {1, 1};
		else {
			vector<int> pre = binomialCoef(n - 1);
			pre.insert(pre.begin(), 0);
			pre.insert(pre.end(), 0);
			vector<int> res;
			int N = pre.size();
			for (int i = 0; i < N - 1; i++) {
				res.push_back(pre[i] + pre[i + 1]);
			}
			return res;
		}
	}
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> output;
		if (numRows <= 0)
			return {};
		for (int i = 1; i <= numRows; i++) {
			vector<int> res = binomialCoef(i);
			output.push_back(res);
		}
		return output;
	}
	vector<vector<int>> generate_loop(int numRows) {
		vector<vector<int>> res(numRows);
		for (int i = 0; i < numRows; numRows++) {
			res[i].resize(i + 1);
			res[i][0] = res[i][i] = 1;
			for (int j = 1; j < i; ++j) {
				res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
			}
		}
		return res;
	}
};

int main() {
	Solution ss;
	int n = 3;
	vector<int> bin = ss.binomialCoef(n);
	for (int i = 0; i < bin.size(); i++)
		cout << bin[i] << "  ";
	return 0;
}