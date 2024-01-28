/*
 * @Date: 2024-01-23 09:33:46
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/103-BN-Tree-ZigZag-Traversal/103.cpp
 * @Description: 
 */
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
// 等价于二叉树层序遍历
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        int l = 0;
        while (!q.empty()) {
            int size = q.size();
            ++l;
            vector<int> level;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (l % 2 == 0)
                reverse(level.begin(), level.end());
            res.push_back(level);
        }
        return res;
    }
};

int main() {

    return 0;
}