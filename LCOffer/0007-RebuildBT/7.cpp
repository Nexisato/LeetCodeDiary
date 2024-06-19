/*
LCOffer 7: Rebuild BT
@Description:
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
	TreeNode* traversal(vector<int>& pre, vector<int>& in, int preL, int preR, int inL,
	                    int inR) {
		if (preL > preR || inL > inR)
			return nullptr;
		int n = pre.size();
		int rootVal = pre[preL];
		TreeNode* node = new TreeNode(rootVal);
		int index = -1;
		for (int i = inL; i <= inR; ++i)
			if (in[i] == rootVal) {
				index = i;
				break;
			}
		node->left = traversal(pre, in, preL + 1, preL + index - inL, inL, index - 1);
		node->right = traversal(pre, in, preL + index - inL + 1, preR, index + 1, inR);
		return node;
	}

public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		return traversal(preorder, inorder, 0, n - 1, 0, n - 1);
	}
};
int main() { return 0; }