/*
LeetCode: 450 Delete Node in a BST
Description:
Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Follow up: Can you solve it with time complexity O(height of tree)?

Constraints:
The number of nodes in the tree is in the range [0, 10^4].
-10^5 <= Node.val <= 10^5
Each node has a unique value.
root is a valid binary search tree.
-10^5 <= key <= 10^5
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
考虑三种情况
1. 叶子节点可以直接删除
2. 若该节点有右子节点，则该节点可以由该节点的后继节点替代，[并删除后继节点]
3. 若该节点有左子节点，则该节点可以由该节点的前驱节点替代，[并删除前驱节点]
要安全删除一个节点应该分两个步骤：
将父节点中指向这个被删除的节点的left或right重新赋值为nullptr
delete该节点
*/
class Solution {
private:
    TreeNode* successor(TreeNode* root) {
        root = root->right;
        while (root->left != nullptr)
            root = root->left;
        return root;
    }
    TreeNode* predecessor(TreeNode* root) {
        root = root->left;
        while (root->right != nullptr)
            root = root->right;
        return root;
    }
public:
    void deleteNode(TreeNode* node, int key, TreeNode* parent) {
        if (!node) return;
        if (key < node->val)
            deleteNode(node->left, key, node);
        else if (key > node->val)
            deleteNode(node->right, key, node);
        else {
            if (!node->left && !node->right) {
                parent->left == node ? parent->left = nullptr : parent->right = nullptr;
                delete node;
            }
            else if (node->right != nullptr) {
                TreeNode *tmp = successor(node);
                swap(node->val, tmp->val);
                deleteNode(node->right, key, node);
            }
            else {
                TreeNode *tmp = predecessor(node);
                swap(node->val, tmp->val);
                deleteNode(node->left, key, node);
            }
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        else if (root->val == key && !root->left && !root->right) {
            delete root;
            return nullptr;
        }
        else
            deleteNode(root, key, nullptr);
        return root;         
    }
};
int main() {
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    Solution ss;
    root = ss.deleteNode(root, 2); 
    return 0;
}