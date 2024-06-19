/*
LeetCode 783: Minimum Distance Between BST Nodes
@Description:
Given the root of a Binary Search Tree (BST), return the minimum difference
between the values of any two different nodes in the tree.

Note: This question is the same as 530:
https://leetcode.com/problems/minimum-absolute-difference-in-bst/

Constraints:
The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 10^5
*/
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
/*
思路：
*/
class Solution {
private:
	int res = INT32_MAX;
	void inorderTraversal(TreeNode* node, int& preVal) {
		if (!node)
			return;
		inorderTraversal(node->left, preVal);
		if (preVal == -1)
			preVal = node->val;
		else
			res = min(res, node->val - preVal);
		inorderTraversal(node->right, node->val);
	}

public:
	int minDiffInBST(TreeNode* root) {
		if (!root)
			return 0;
		int preVal = -1;
		inorderTraversal(root, preVal);
		return res;
	}
};
int main() { return 0; }