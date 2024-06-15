#include <bits/stdc++.h>
using namespace std;
/**
 * @brief
 * 回溯法，思路同 Solution 77
 * n - (k - path.size()) + 1 这一剪枝一定要注意
 */
class Solution {
private:
	vector<vector<int>> res;
	vector<int> path;
	void backtracking(int targetSum, int sum, int k, int startNum) {
		if (sum > targetSum)
			return;
		if (path.size() == k) {
			if (sum == targetSum)
				res.push_back(path);
			return;
		}
		for (int i = startNum; i <= 9 - (k - path.size()) + 1; ++i) {
			sum += i;
			path.push_back(i);
			backtracking(targetSum, sum, k, i + 1);
			sum -= i;
			path.pop_back();
		}
	}

public:
	vector<vector<int>> combinationSum3(int k, int n) {
		res.clear();
		path.clear();
		backtracking(n, 0, k, 1);
		return res;
	}
};
int main() { return 0; }