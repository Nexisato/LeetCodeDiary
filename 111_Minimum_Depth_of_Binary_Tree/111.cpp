/*
LeetCode 111: Minimum Depth of Binary Tree
@Description:
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down 
 the nearest leaf node.

Note: A leaf is a node with no children.

Constraints:
The number of nodes in the tree is in the range [0, 10^5].
-1000 <= Node.val <= 1000
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
DFS，不过要分左右子树是否存在的情况讨论
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        int depth = INT32_MAX;
        if (root->left)
            depth = min(1 + minDepth(root->left), depth);
        if (root->right)
            depth = min(1 + minDepth(root->right), depth);
        return depth;
    }
};
int main() {


    return 0;
}