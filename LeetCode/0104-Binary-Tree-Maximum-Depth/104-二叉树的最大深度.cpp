/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		int left_depth = 1 + maxDepth(root->left);
		int right_depth = 1 + maxDepth(root->right);
		return left_depth > right_depth ? left_depth : right_depth;
	}
};