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
/**
 * @brief
 *
 *
 */
class Solution {
public:
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (!root)
			return nullptr;
		if (root->val < low)
			return trimBST(root->right, low, high);
		if (root->val > high)
			return trimBST(root->left, low, high);

		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
		return root;
	}
	TreeNode* trimBST_iter(TreeNode* root, int low, int high) {
		if (!root)
			return nullptr;

		while (root && ((root->val < low) || (root->val > high))) {
			if (root->val < low)
				root = root->right;
			else
				root = root->left;
		}
		// root 移动到 [low, high] 区间，处理左子树中 < low 的情况
		TreeNode* cur = root;
		while (cur) {
			while (cur->left && cur->left->val < low) {
				cur->left = cur->left->right;
			}
			cur = cur->left;
		}

		cur = root;
		// root 移动到 [low, high] 区间，处理右子树中 > high 的情况
		while (cur) {
			while (cur->right && cur->right->val > high) {
				cur->right = cur->right->left;
			}
			cur = cur->right;
		}
		return root;
	}
};
int main() { return 0; }