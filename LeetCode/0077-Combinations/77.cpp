/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0077-Combinations/77.cpp
 * @Description:
 */
#include <iostream>
#include <vector>
using namespace std;
/**
 * @brief
 * 回溯算法 basis
 *
 * 确定返回值和参数
 * 确定终止条件 / 叶子结点
 * 处理单层逻辑：for 循环遍历 N 叉树宽度，递归遍历N叉树深度
 *
 */
class Solution {
private:
	vector<vector<int>> res;
	vector<int> path;
	void backtracking(int n, int k, int startNum) {
		if (path.size() == k) {
			res.push_back(path);
			return;
		}
		for (int i = startNum; i <= n - (k - path.size()) + 1; ++i) {
			path.push_back(i);
			backtracking(n, k, i + 1);
			path.pop_back();
		}
	}

public:
	vector<vector<int>> combine(int n, int k) {
		path.clear();
		res.clear();
		backtracking(n, k, 1);
		return res;
	}
};
int main() { return 0; }