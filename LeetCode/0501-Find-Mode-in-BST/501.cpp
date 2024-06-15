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
 * 若此题非 BST ，需要额外的 map 记录
 * BST 可用一个 pre 节点记录，与 cur 进行对比
 *
 */
class Solution {
private:
	int count = 0, maxCount = 0;
	vector<int> res;
	TreeNode* pre = nullptr;
	void traversal(TreeNode* node) {
		if (!node)
			return;
		traversal(node->left);

		if (!pre) {
			count = 1;
		} else if (pre->val == node->val) {
			++count;
		} else {
			count = 1;
		}
		pre = node;

		if (count == maxCount)
			res.push_back(node->val);

		if (count > maxCount) {
			res.clear();
			maxCount = count;
			res.push_back(node->val);
		}

		traversal(node->right);
	}

public:
	vector<int> findMode(TreeNode* root) {
		traversal(root);
		return res;
	}
};
int main() { return 0; }