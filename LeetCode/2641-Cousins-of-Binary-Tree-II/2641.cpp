/*
 * @Date: 2024-02-07 09:35:09
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2641-Cousins-of-Binary-Tree-II/2641.cpp
 * @Description:
 */
#include <iostream>
#include <queue>
#include <string>
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
// cousins-of-binary-tree-ii
class Solution {
public:
	TreeNode* replaceValueInTree(TreeNode* root) {
		if (!root)
			return nullptr;
		vector<TreeNode*> q;
		root->val = 0;
		q.emplace_back(root);
		int sum = 0;
		// 每次遍历更新子节点的值即可
		while (!q.empty()) {
			sum = 0;
			vector<TreeNode*> tmp;
			// 本层所有子节点的值相加
			for (auto& node : q) {
				if (node->left) {
					tmp.emplace_back(node->left);
					sum += node->left->val;
				}
				if (node->right) {
					tmp.emplace_back(node->right);
					sum += node->right->val;
				}
			}
			// 本层当前子节点之外其他子节点的值相加
			for (auto& node : q) {
				int other = (node->left ? node->left->val : 0) +
				            (node->right ? node->right->val : 0);
				if (node->left)
					node->left->val = sum - other;
				if (node->right)
					node->right->val = sum - other;
			}
			// 转移所有权
			q = std::move(tmp);
		}

		return root;
	}
};
int main() { return 0; }