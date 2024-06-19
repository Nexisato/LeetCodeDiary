/*
LeetCode 1008: Construct BST from Preorder
@Description:
Given an array of integers preorder, which represents the preorder traversal of a
BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the
given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left
has a value strictly less than Node.val, and any descendant of Node.right has a value
strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first,
then traverses Node.left, then traverses Node.right.

Constraints:
1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
All the values of preorder are unique.
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r){};
};
/*
思路：利用上下限递归构造
*/
class Solution {
private:
	int i = 0;
	TreeNode* rebuild(vector<int>& preorder, int n, int low, int up) {
		if (i == n)
			return nullptr;
		int val = preorder[i];
		if (val < low || val > up)
			return nullptr;
		i++;
		TreeNode* node = new TreeNode(val);
		node->left = rebuild(preorder, n, low, val);
		node->right = rebuild(preorder, n, val, up);
		return node;
	}

public:
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		int n = preorder.size();
		return rebuild(preorder, n, INT32_MIN, INT32_MAX);
	}
};
int main() { return 0; }