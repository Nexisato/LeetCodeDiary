/*
Description:
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia:
“The lowest common ancestor is defined between two nodes p and q 
as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Constraints:
The number of nodes in the tree is in the range [2, 10^5].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q will exist in the tree.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	//不要用isExist，会无限制地增加节点访问次数
	/*private:
	    bool isExist(TreeNode *node,TreeNode *p){
	        //判断p是否在node的子树上
	        if(!node) return false;
	        if(node==p) return true;
	        else return isExist(node->left,p) || isExist(node->right,p);
	    }*/
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root)
			return NULL;
		if (root == q || root == p)
			return root;

		TreeNode* lnode = lowestCommonAncestor(root->left, p, q);
		TreeNode* rnode = lowestCommonAncestor(root->right, p, q);

		if (!lnode)
			return rnode;
		if (!rnode)
			return lnode;
		if (lnode && rnode)
			return root; // p q若在同一侧 lnode，则另一侧 rnode值必为null

		return NULL;
	}
};

int main() { return 0; }