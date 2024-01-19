/*
LeetCode: 114 Flatten Binary Tree to Linked List
Description:
Given a binary tree, flatten it to a linked list in-place.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：递归(dong)
1. 将左子树和右子树拉平
2. 将root的右子树接到左子树的下方，然后将左子树作为root的右子树

*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; 
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->left);
        flatten(root->right);

        TreeNode* lnode = root->left;
        TreeNode* rnode = root->right;

        root->left = nullptr;
        root->right = lnode;

        TreeNode *node = root;
        while (node->right)
            node = node->right;
        node->right = rnode;
};
int main() {

    return 0;
}