#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
/**
 * 思路：只交换奇数层的节点
 * 1. 层序遍历，奇数层的节点入队
 */
class Solution {
public:
    TreeNode *reverseOddLevels(TreeNode *root) {
        queue<TreeNode *> q;
        int level = 0;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode *> tmpNode;
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (level % 2 == 1) {
                    tmpNode.push_back(node);
                }
                if (node->left) {
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (level % 2 == 1) {
                for (int l = 0, r = size - 1; l < r; ++l, --r) {
                    swap(tmpNode[l]->val, tmpNode[r]->val);
                }
            }
            ++level;
        }
        return root;
    }
};
int main() { return 0; }