#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
/*
思路：使用hashtable快速定位根节点
1. 对于hash映射中的每一个键值对，键表示一个元素节点值，值表示该元素在中序遍历中的出现位置
*/
class Solution {
private:
    unordered_map<int, int> table;
    TreeNode *traversal(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR) {
        if (preL > preR)
            return nullptr;
        int inroot = table[preorder[preL]];

        TreeNode* node = new TreeNode(preorder[preL]);
        int left_len = inroot - inL;
        node->left = traversal(preorder, inorder, preL + 1, preL + left_len, inL, inroot - 1);
        node->right = traversal(preorder, inorder, preL + left_len + 1, preR, inroot + 1, inR);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return traversal(preorder, inorder);
    }

};
int main()
{

    return 0;
}