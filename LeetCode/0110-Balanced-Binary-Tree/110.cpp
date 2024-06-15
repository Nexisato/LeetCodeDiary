#include <bits/stdc++.h>
using namespace std;
//  Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/**
 * @brief
 * 深度：从 根节点 到 该节点 的最长简单路径边的条数
 * 高度：从 该节点 到 叶子节点 的最长简单路径边的条数
 */
class Solution {
private:
	int getHeight(TreeNode* node) {
		if (!node)
			return 0;

		int leftHeight = getHeight(node->left);
		if (leftHeight == -1)
			return -1;
		int rightHeight = getHeight(node->right);
		if (rightHeight == -1)
			return -1;

		if (abs(leftHeight - rightHeight) > 1)
			return -1;

		return 1 + max(leftHeight, rightHeight);
	}

public:
	bool isBalanced(TreeNode* root) { return (getHeight(root) == -1) ? false : true; }
};
int main() { return 0; }