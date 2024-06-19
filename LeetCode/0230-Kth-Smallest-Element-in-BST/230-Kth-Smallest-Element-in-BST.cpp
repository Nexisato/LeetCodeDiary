/*
LeetCode: 230 Kth Smallest Element in BST
Description:
Given a binary search tree, write a function kthSmallest to find the kth smallest
element in it.

Follow up:
What if the BST is modified (insert/delete operations) often and
you need to find the kth smallest frequently? How would you optimize the kthSmallest
routine?

Constraints:
The number of elements of the BST is between 1 to 10^4.
You may assume k is always valid, 1 ≤ k ≤ BST's total elements
*/
#include <iostream>
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
1. BST的中序遍历为升序数组，因此中序遍历到第k个值即可
2.
*/
class Solution {
	int res;
	int rank = 0;

private:
	void traverse(TreeNode* root, int k) {
		if (!root)
			return;
		traverse(root->left, k);
		if (++rank == k) {
			res = root->val;
			return;
		}
		traverse(root->right, k);
	}

public:
	int kthSmallest(TreeNode* root, int k) {
		traverse(root, k);
		return res;
	}
};
int main() { return 0; }