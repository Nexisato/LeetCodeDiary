#include <bits/stdc++.h>
using namespace std;
/**
 * @brief
 *
 */
class Solution {
private:
	vector<vector<int>> res;
	vector<int> path;
	void backtracking(const vector<int>& candidates, int target, int sum, int startIndex) {
		if (sum > target)
			return;
		if (sum == target) {
			res.push_back(path);
			return;
		}
		for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; ++i) {
			if (i > startIndex && candidates[i] == candidates[i - 1]) //数层跳过
				continue;
			sum += candidates[i];
			path.push_back(candidates[i]);
			backtracking(candidates, target, sum, i + 1); //树枝不用跳过
			sum -= candidates[i];
			path.pop_back();
		}
	}

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		res.clear();
		path.clear();
		backtracking(candidates, target, 0, 0);
		return res;
	}
};
int main() { return 0; }