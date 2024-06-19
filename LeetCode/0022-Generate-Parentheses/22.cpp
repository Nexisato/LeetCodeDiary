/*
 * @Date: 2024-02-08 08:10:47
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0022-Generate-Parentheses/22.cpp
 * @Description:
 */
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 回溯硬搜
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		function<void(int, int, string&, vector<string>&)> dfs =
		    [&](int left, int right, string& path, vector<string>& res) {
			    if (left == 0 && right == 0) {
				    res.emplace_back(path);
				    return;
			    }
			    if (left > 0) {
				    path.push_back('(');
				    dfs(left - 1, right, path, res);
				    path.pop_back();
			    }
			    if (right > left) {
				    path.push_back(')');
				    dfs(left, right - 1, path, res);
				    path.pop_back();
			    }
		    };
		string path;
		dfs(n, n, path, res);

		return res;
	}
};
int main() { return 0; }