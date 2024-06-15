/*
LeetCode: 654 Maximum Binary Tree
Description:
You are given an integer array nums with no duplicates.
A maximum binary tree can be built recursively from nums using the following algorithm:

Create a root node whose value is the maximum value in nums.
Recursively build the left subtree on the subarray prefix to the left of the maximum value.
Recursively build the right subtree on the subarray suffix to the right of the maximum value.
Return the maximum binary tree built from nums.

Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 1000
All integers in nums are unique.
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
思路：递归
1. 在固定区间 [l ,r] 内遍历得到 nums 数组中的最大值 max_val
2. 以 max_val 所在的位置为分界点，左半部分递归构造左子树，右半部分递归构造右子树
*/

class Solution {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) { return build(nums, 0, nums.size() - 1); }
	TreeNode* build(vector<int>& nums, int l, int r) {
		if (l > r)
			return nullptr;
		int max_val = INT32_MIN, max_index = -1;
		for (int i = l; i <= r; i++)
			if (nums[i] > max_val) {
				max_val = nums[i];
				max_index = i;
			}
		TreeNode* node = new TreeNode(max_val);
		node->left = build(nums, l, max_index - 1);
		node->right = build(nums, max_index + 1, r);
		return node;
	}
};
int main() { return 0; }