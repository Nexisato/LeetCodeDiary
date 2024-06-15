/*
 * @Date: 2024-02-15 08:59:51
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0107-Binary-Tree-Level-Order-II/107.cpp
 * @Description:
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		if (!root)
			return res;
		queue<TreeNode*> q;
		q.push(root);
		vector<int> level;
		while (!q.empty()) {
			int n = q.size();
			level = std::move(vector<int>());
			for (int i = 0; i < n; ++i) {
				TreeNode* node = q.front();
				q.pop();
				level.push_back(node->val);
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
			res.push_back(level);
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
int main() { return 0; }