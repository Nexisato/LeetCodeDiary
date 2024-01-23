/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0098-Validate-Binary-Search-Tree/98-Validate-Binary-Search-Tree.cpp
 * @Description: 
 */
/*
LeetCode: 98 Validate Binary Search Tree
Description:
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Constraints:
The number of nodes in the tree is in the range [1, 10^4].
-2^31 <= Node.val <= 2^31 - 1
*/
#include <iostream>
#include <vector>
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
思路：递归
1. 对于单个二叉搜索树节点，仅仅判断其子节点与该节点的大小关系，会得到错误的结果
2. BST要求该节点的左子树所有节点都比它小，而其右子树的所有节点都比它大
3. 引入lower和upper节点，分别代表当前访问的节点的上下界
    -三个参数值分别代表：当前节点，当前节点的下界，当前节点的上界
    -isValidBST(node->left, lower, node)，node是node的左子树的上界，下界还未知
    -isValidBST(node->right, node, upper); node是node的右子树的下界，上界还未知

*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
    bool isValidBST(TreeNode* node, TreeNode* lower, TreeNode* upper) { //max->val > root->val > min->val
        if (!node) return true;
        if (lower != nullptr && node->val <= lower->val) return false;
        if (upper != nullptr && node->val >= upper->val) return false;
        return isValidBST(node->left, lower, node) && isValidBST(node->right, node, upper);
    }
};
/*
思路：
验证二叉搜索树，即 中序遍历 二叉树，判断其是否递增
*/
class Solution2 {
private:
    vector<int> node;
    void traversal(TreeNode* root) {
        if (!root) return;
        traversal(root->left);
        node.push_back(root->val);
        traversal(root->right);
    }
public:
   
    bool isValidBST(TreeNode* root) {
        node.clear();
        traversal(root);
        for(int i = 1; i < node.size(); i++)
            if (node[i] <= node[i-1]) return false;
        return true;
    }
};
// 中序遍历，记录 Pre 节点，大于等于 cur 节点就return false
class Solution_3 {
private:
    TreeNode* pre;
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        bool left = isValidBST(root->left);
        if (pre && pre->val >= root->val) return false;
        pre = root;
        bool right = isValidBST(root->right);
        return left && right;
    }
};
int main() {

    return 0;
}