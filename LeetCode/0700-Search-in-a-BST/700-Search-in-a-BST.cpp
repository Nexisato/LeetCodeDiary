/*
LeetCode: 700 Search in a Binary Search Tree
Description:
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and
return the subtree rooted with that node. If such a node does not exist, return null.

Constraints:
The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 10^7
root is a binary search tree.
1 <= val <= 10^7
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
/*
思路：BST二分查找
*/
class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if (!root)
			return nullptr;
		if (root->val == val)
			return root;
		if (root->left && val < root->val)
			return searchBST(root->left, val);
		if (root->right && val > root->val)
			return searchBST(root->right, val);
		return nullptr;
	}
};

int main() { return 0; }