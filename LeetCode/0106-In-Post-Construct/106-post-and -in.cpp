/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0106_中序遍历和后序遍历恢复二叉树/106_post_and
 * _in.cpp
 * @Description:
 */
#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
思路：同pre and in
*/
class Solution {
private:
	unordered_map<int, int> table;
	TreeNode* traversal(vector<int>& postorder, vector<int>& inorder, int postL,
	                    int postR, int inL, int inR) {
		if (postL > postR)
			return nullptr;
		int inroot = table[postorder[postR]];

		TreeNode* node = new TreeNode(postorder[postR]);
		int left_len = inroot - inL;
		node->left =
		    traversal(postorder, inorder, postL, postL + left_len - 1, inL, inroot - 1);
		node->right =
		    traversal(postorder, inorder, postL + left_len, postR - 1, inroot + 1, inR);
		return node;
	}

public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = inorder.size();
		for (int i = 0; i < n; ++i)
			table[inorder[i]] = i;
		return traversal(postorder, inorder, 0, n - 1, 0, n - 1);
	}
};
/*
思路：参数中多引入几个标记索引
*/
class Solution {
private:
	TreeNode* rebuild(vector<int>& inorder, vector<int>& postorder, int inL, int inR,
	                  int postL, int postR) {
		if (inL > inR)
			return nullptr;
		TreeNode* node = new TreeNode(postorder[postR]);
		for (int i = inL; i <= inR; ++i)
			if (inorder[i] == postorder[postR]) {
				node->left =
				    rebuild(inorder, postorder, inL, i - 1, postL, postL + i - 1 - inL);
				node->right =
				    rebuild(inorder, postorder, i + 1, inR, postL + i - inL, postR - 1);
				break;
			}
		return node;
	}

public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return rebuild(inorder, postorder, 0, inorder.size() - 1, 0,
		               postorder.size() - 1);
	}
};
int main() { return 0; }