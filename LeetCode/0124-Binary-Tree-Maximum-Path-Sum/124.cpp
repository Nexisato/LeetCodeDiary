/*
 * @Date: 2024-01-18 16:49:49
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0124_Binary_Tree_Maximum_Path_Sum/124.cpp
 * @Description: 
 */
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
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

class Solution {
// 下面这个是相当麻烦的回溯，实际上可以不用的，非常快的后序遍历一次即可
private:
    unordered_map<TreeNode*, vector<TreeNode*>> tables;
    unordered_set<TreeNode*> isVisited;
    vector<TreeNode*> nodes;
    void traversal(TreeNode* node) {
        if (!node)
            return;
        nodes.push_back(node);
        if (node->left) {
            tables[node].push_back(node->left);
            tables[node->left].push_back(node);
        }
        if (node->right) {
            tables[node].push_back(node->right);
            tables[node->right].push_back(node);
        }
        traversal(node->left);
        traversal(node->right);
    }
    int getPath(TreeNode* node, unordered_set<TreeNode*>& isVisited) {
        if (!node)
            return 0;
        if (node->val < 0)
            return 0;
        int res = node->val;
        int maxPath = res;
        for (auto& neighbor : tables[node]) {
            res = node->val;
            if (!isVisited.count(neighbor)) {
                isVisited.insert(neighbor);
                res += getPath(neighbor, isVisited);
                maxPath = max(maxPath, res);
                isVisited.erase(neighbor);
            }
        }
        return maxPath;
    }
    int maxVal = INT_MIN;
public:
    // 会超时，不用这么麻烦
    int maxPathSum_backtracking(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val;
        traversal(root);
        isVisited.clear();
        int res = INT_MIN;
        for (auto& node : nodes) {
            isVisited.insert(node);
            res = max(res, getPath(node, isVisited));
            isVisited.erase(node);
        }
        
        return res;
    }
    int maxCurPath(TreeNode* node) {
        if (!node)
            return 0;
        int leftPath = max(0, maxCurPath(node->left));
        int rightPath = max(0, maxCurPath(node->right));

        // 一个是路径，一个是贡献值，不用全加
        int curPath = node->val + leftPath + rightPath;

        maxVal = max(maxVal, curPath);

        return node->val + max(leftPath, rightPath);
    }
    int maxPathSum(TreeNode* root) {
        maxCurPath(root);
        return maxVal;
    }
};
int main() {

    return 0;
}