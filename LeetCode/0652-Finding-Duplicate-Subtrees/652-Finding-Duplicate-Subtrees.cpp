/*
LeetCode: 652 Finding Duplicate Subtrees
Description:
Given the root of a binary tree, return all duplicate subtrees.
For each kind of duplicate subtrees, you only need to return the root node of any one of
them. Two trees are duplicate if they have the same structure with the same node values.

Constraints:
The number of the nodes in the tree will be in the range [1, 10^4]
-200 <= Node.val <= 200
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
1. 前序序列 + hash
    将一棵二叉树的所有节点作为根节点进行前序遍历，记录重复出现的前序序列字符串
    hash : key-前序序列字符串；value：字符串出现的次数
*/
class Solution {
	vector<TreeNode*> res;
	unordered_map<string, int> hash;

public:
	string preSerial(TreeNode* root) {
		if (!root)
			return "NULL";
		string left = preSerial(root->left);
		string right = preSerial(root->right);
		string cur = to_string(root->val) + " " + left + " " + right;
		if (++hash[cur] == 2)
			res.push_back(root);
		return cur;
	}
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		res.clear();
		preSerial(root);
		return res;
	}
};
int main() { return 0; }