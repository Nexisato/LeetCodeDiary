/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0222_Count_Complete_Binary_TreeNodes/222_Count_Complete_Binary_Tree_Nodes.cpp
 * @Description:
 */
/*
LeetCode: 222 Count Complete Binary Tree Nodes
Description:
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last,
is completely filled in a complete binary tree,
and all nodes in the last level are as far left as possible.
It can have between 1 and 2h nodes inclusive at the last level h.

Constraints:
The number of nodes in the tree is in the range [0, 5 * 10^4].
0 <= Node.val <= 5 * 10^4
The tree is guaranteed to be complete.
*/
#include <iostream>
#include <vector>
using namespace std;
/*
思路：递归
1. 普通二叉树，直接前序遍历计算可得结果
2. Perfect Binary Tree的节点个数为 2^h - 1，h 为满二叉树的深度；
3. 完全二叉树介于普通二叉树和满二叉树之间，因此可进一步优化其时间复杂度
*/

//  Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (!root)
			return 0;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
	int countNodes_opt(TreeNode* root) {
		if (!root)
			return 0;
		TreeNode *lnode = root, *rnode = root;
		int hl = 0, hr = 0;
		while (lnode) {
			lnode = lnode->left;
			hl++;
		}
		while (rnode) {
			rnode = rnode->right;
			hr++;
		}
		if (hl == hr)
			return (int)pow(2, hl) - 1; // (2 << h1) - 1
		else
			return 1 + countNodes(root->left) + countNodes(root->right);
	}
};
int main() { return 0; }