/*
LeetCode 897: Increasing Order Search Tree
@Description:
Given the root of a binary search tree, rearrange the tree in in-order so that the
leftmost node in the tree is now the root of the tree, and every node has no left child
and only one right child.

Constraints:
The number of nodes in the given tree will be in the range [1, 100].
0 <= Node.val <= 1000
*/
#include <bits/stdc++.h>
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
private:
	vector<int> inOrderList;
	void traversal(TreeNode* node) {
		if (!node)
			return;
		traversal(node->left);
		inOrderList.emplace_back(node->val);
		traversal(node->right);
	}

public:
	TreeNode* increasingBST(TreeNode* root) {
		if (root == nullptr)
			return nullptr;
		inOrderList.clear();
		TreeNode *virnode = new TreeNode(-1), *record = virnode;
		traversal(root);
		for (int i = 0; i < inOrderList.size(); ++i) {
			TreeNode* node = new TreeNode(inOrderList[i]);
			virnode->right = node;
			virnode = node;
		}
		return record->right;
	}
};
int main() { return 0; }