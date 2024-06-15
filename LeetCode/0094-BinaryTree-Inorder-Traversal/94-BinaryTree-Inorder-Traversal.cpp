/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0094-BinaryTree-Inorder-Traversal/94-BinaryTree-Inorder-Traversal.cpp
 * @Description:
 */
/*
Description:
Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/

#include <iostream>
#include <stack>
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
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> tmp;
		vector<int> outputs;
		TreeNode* node = root;
		while (node != nullptr || !tmp.empty()) {
			if (node != nullptr) {
				tmp.push(node);
				node = node->left;
			} else {
				node = tmp.top();
				tmp.pop();
				outputs.push_back(node->val);
				// tmp.push(node->right);
				node = node->right;
			}
		}
		return outputs;
	}
};
int main() { return 0; }