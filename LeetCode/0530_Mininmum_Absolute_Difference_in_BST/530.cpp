/*
LeetCode 539: Minimum Absolute Difference in BST
@Description:
Given a binary search tree with non-negative values, find the minimum absolute 
difference between values of any two nodes.
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
思路：中序遍历，记录节点（注意要使用引用）
*/
class Solution {
private:
    void inorderTraversal(TreeNode* root, int& preVal, int& res) {
        if (root == nullptr)
            return;
        inorderTraversal(root->left, preVal, res);
        if (preVal == -1)
            preVal = root->val;
        else {
            res = min(res, abs(root->val - preVal));
            preVal = root->val;
        }
        inorderTraversal(root->right, preVal, res);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int res = INT32_MAX, preVal = -1;
        inorderTraversal(root, preVal, res);
        return res;
    }
};
int main() {


    return 0;
}