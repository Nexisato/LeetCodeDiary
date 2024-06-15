/*
LeetCode: 226 Invert Binary Tree
Description:
Invert a binary tree.

Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew),
but you can’t invert a binary tree on a whiteboard so f*** off.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：递归
1. 模板：二叉树的前序遍历 或 后序遍历
2. 将二叉树的每一个节点互换，得到的最终结果就是一个翻转过后的二叉树
*/
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root)
			return nullptr;
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};
int main() { return 0; }