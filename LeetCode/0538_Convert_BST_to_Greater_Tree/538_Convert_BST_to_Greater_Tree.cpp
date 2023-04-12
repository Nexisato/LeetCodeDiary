/*
LeetCode: 538 Convert BST to Greater Tree
Description:
Given the root of a Binary Search Tree (BST), convert it to a Greater Sum Tree such that 
every key of the original BST is changed to the original key plus 
sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Note: This question is the same as 1038:
https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

Constraints:
The number of nodes in the tree is in the range [0, 10^4].
-10^4 <= Node.val <= 10^4
All the values in the tree are unique.
root is guaranteed to be a valid binary search tree.
*/
#include <bits/stdc++.h>
using namespace std;
//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
思路：
1. 递归：反向中序遍历
累加树即反向中序遍历得到的结果
*/
class Solution {
private:
    int pre = 0;
    int preVal = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root != nullptr) {
            convertBST(root->right);
            pre += root->val;
            root->val = pre;
            convertBST(root->left);
        }
        return root;
    }

    TreeNode* convertBST_iter(TreeNode* root) {
        if (!root) return nullptr;
        preVal = 0;
        TreeNode *node = root;
        vector<TreeNode*> st;
        while (node || !st.empty()) {
            if (node) {
                st.push_back(node);
                node = node->right;
            } else {
                node = st.back();
                st.pop_back();
                node->val += preVal;
                preVal = node->val;
                node = node->left;
            }
        }
        return root;
    }
};
int main() {

    return 0;
}