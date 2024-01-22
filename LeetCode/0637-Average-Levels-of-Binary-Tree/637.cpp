/*
 * @Date: 2024-01-22 09:32:37
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0637-Average-Levels-of-Binary-Tree/637.cpp
 * @Description: 
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) return res;
        TreeNode *node = root;
        queue<TreeNode *> q;
        q.push(node);

        while (!q.empty()) {
            int size = q.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.push_back(sum / size);
        }
        return res;
    }
};
int main() {

    return 0;
}