/*
面试题01.08: Zero Matrix LCCI
Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
*/
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		vector<bool> rowRecord(m, false), colRecord(n, false);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j)
				if (matrix[i][j] == 0) {
					colRecord[j] = true;
					rowRecord[i] = true;
				}
		}
		for (int i = 0; i < m; ++i)
			if (rowRecord[i])
				for (int j = 0; j < n; ++j)
					matrix[i][j] = 0;
		for (int j = 0; j < n; ++j)
			if (colRecord[j])
				for (int i = 0; i < m; ++i)
					matrix[i][j] = 0;
	}
};
int main() { return 0; }