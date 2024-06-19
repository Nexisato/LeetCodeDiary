/*
 * @Date: 2024-02-23 22:41:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/1145-Binary-Tree-Coloring-Game/1145.cpp
 * @Description:
 */
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 3 种情况
// 只要能找到一个节点，使得它的子树节点数大于 n / 2，就能赢
class Solution {
public:
	bool btreeGameWinningMove(TreeNode* root, int n, int x) {
		function<int(TreeNode*)> getCount = [&](TreeNode* node) -> int {
			if (!node)
				return 0;
			return 1 + getCount(node->left) + getCount(node->right);
		};

		function<TreeNode*(TreeNode*, int)> getNode = [&](TreeNode* node,
		                                                  int val) -> TreeNode* {
			if (!node)
				return nullptr;
			if (node->val == val)
				return node;
			TreeNode* left = getNode(node->left, val);
			TreeNode* right = getNode(node->right, val);
			return left ? left : right;
		};

		TreeNode* node = getNode(root, x);
		int l_count = getCount(node->left);
		int r_count = getCount(node->right);
		int threshold = n / 2;

		return l_count > threshold || r_count > threshold ||
		       l_count + r_count < threshold;
	}
};
int main() { return 0; }