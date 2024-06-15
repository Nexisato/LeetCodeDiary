/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> tmp;
		vector<int> outputs;
		tmp.push(root);
		while (!tmp.empty()) {
			TreeNode* curr = tmp.top();
			tmp.pop();
			if (curr != nullptr)
				outputs.push_back(curr->val);
			else
				continue;
			tmp.push(curr->left);
			tmp.push(curr->right);
		}
		reverse(outputs.begin(), outputs.end());
		return outputs;
	}
};