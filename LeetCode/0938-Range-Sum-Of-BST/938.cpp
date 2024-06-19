/*
LeetCode 938: Range Sum of BST
@Description:
Given the root node of a binary search tree, return the sum of values of all nodes with
a value in the range [low, high].

Constraints:
The number of nodes in the tree is in the range [1, 2 * 10^4].
1 <= Node.val <= 10^5
1 <= low <= high <= 10^5
All Node.val are unique.
*/
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
/*
思路：

*/
class Solution {
private:
	int sum = 0;
	void Traversal(TreeNode* node, int low, int high) {
		if (node == nullptr)
			return;
		Traversal(node->left, low, high);
		if (low <= node->val && high >= node->val)
			sum += node->val;
		Traversal(node->right, low, high);
	}

public:
	int rangeSumBST(TreeNode* root, int low, int high) {
		sum = 0;
		Traversal(root, low, high);
		return sum;
	}
};
int main() { return 0; }