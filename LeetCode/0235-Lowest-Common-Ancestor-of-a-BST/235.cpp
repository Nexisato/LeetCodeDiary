#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * @brief
 *
 */
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root)
			return nullptr;
		if (root->val > p->val && root->val > q->val) {
			TreeNode* lnode = lowestCommonAncestor(root->left, p, q);
			if (lnode)
				return lnode;
		}
		if (root->val < p->val && root->val < q->val) {
			TreeNode* rnode = lowestCommonAncestor(root->right, p, q);
			if (rnode)
				return rnode;
		}
		return root;
	}
};
int main() { return 0; }