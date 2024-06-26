/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath:
 * /LeetCodeDiary/LeetCode/0102-Level-Traversal-Binary-Tree/102-二叉树的层序遍历.cpp
 * @Description:
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> q;
		vector<vector<int>> outputs;
		if (root != nullptr)
			q.push(root);
		while (!q.empty()) {
			vector<int> tmp;
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				TreeNode* node = q.front();
				tmp.push_back(node->val);
				q.pop();
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
			outputs.push_back(tmp);
		}
		return outputs;
	}
};