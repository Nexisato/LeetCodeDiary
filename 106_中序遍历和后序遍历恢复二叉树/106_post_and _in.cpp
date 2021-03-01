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
思路：同pre and in
*/ 
class Solution {
private:
    unordered_map<int, int> table;
    TreeNode *traversal(vector<int>& postorder, vector<int>& inorder, int postL, int postR, int inL, int inR) {
        if (postL > postR)
            return nullptr;
        int inroot = table[postorder[postR]];

        TreeNode* node = new TreeNode(postorder[postR]);
        int left_len = inroot - inL;
        node->left = traversal(postorder, inorder, postL, postL + left_len - 1, inL, inroot - 1);
        node->right = traversal(postorder, inorder, postL + left_len, postR - 1, inroot + 1, inR);
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

int main()
{

    return 0;
}