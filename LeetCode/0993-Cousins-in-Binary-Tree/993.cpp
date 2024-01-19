/*
LeetCode 993: Cousins in Binary Tree
@Description:
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

Constraints:
The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
*/
#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 /*
 思路：BFS/DFS

 */
class Solution {
private:
    int x;
    TreeNode *parent_x;
    int x_depth;
    bool x_found = false;

    int y;
    TreeNode *parent_y;
    int y_depth;
    bool y_found = false;

    void update(TreeNode* node, TreeNode *parent, int depth) {
        if (node->val == x) {
            std::tie(parent_x, x_depth, x_found) = std::tuple<TreeNode*, int, bool>(parent, depth, true);
        }
        else if (node->val == y) {
            std::tie(parent_y, y_depth, y_found) = std::tuple<TreeNode*, int, bool>(parent, depth, true);
        }
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        this->x = x;
        this->y = y;
        std::queue<std::pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        while (!q.empty()) {
            auto [node, depth] = q.front();
            if (node->left) {
                q.emplace(node->left, depth + 1);
                update(node->left, node, depth + 1);
            }
            if (node->right) {
                q.emplace(node->right, depth + 1);
                update(node->right, node, depth + 1);
            }
            if (x_found && y_found)
                break;
            q.pop();
        }
        return (x_depth == y_depth) && (parent_x != parent_y);
    }
};
int main() {

    return 0;
}