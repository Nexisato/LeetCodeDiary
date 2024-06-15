/*
LeetCode: 1038 Convert BST to Greater Tree
Description:
Given the root of a Binary Search Tree (BST), convert it to a Greater Sum Tree such that
every key of the original BST is changed to the original key plus
sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Note: This question is the same as 538:
https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

Constraints:
The number of nodes in the tree is in the range [0, 10^4].
-10^4 <= Node.val <= 10^4
All the values in the tree are unique.
root is guaranteed to be a valid binary search tree.
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

class Solution {
private:
	int pre = 0;

public:
	TreeNode* bstToGst(TreeNode* root) {
		if (root != nullptr) {
			bstToGst(root->right);
			pre += root->val;
			root->val = pre;
			bstToGst(root->left);
		}
		return root;
	}
};