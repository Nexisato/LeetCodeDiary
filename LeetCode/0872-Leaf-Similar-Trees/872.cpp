/*
LeetCode 872: Leaf-Similar Trees
@Description:
Consider all the leaves of a binary tree, from left to right order,
the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

Constraints:
The number of nodes in each tree will be in the range [1, 200].
Both of the given trees will have values in the range [0, 200].
*/
#include <bits/stdc++.h>
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
/*
思路：中序遍历检测元素
*/
class Solution {
private:
	void traversal(TreeNode* node, vector<int>& seq) {
		if (node == nullptr)
			return;
		traversal(node->left, seq);
		if (!node->left && !node->right)
			seq.emplace_back(node->val);
		traversal(node->right, seq);
	}

public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> seq1, seq2;
		traversal(root1, seq1);
		traversal(root2, seq2);
		int n1 = seq1.size(), n2 = seq2.size();
		if (n1 != n2)
			return false;
		for (int i = 0; i < n1; ++i)
			if (seq1[i] != seq2[i])
				return false;
		return true;
	}
};
int main() { return 0; }