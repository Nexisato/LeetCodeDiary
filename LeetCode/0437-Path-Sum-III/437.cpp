#include <gtest/gtest.h>

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 同 560，前缀和记录当前路径和
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
private:
    unordered_map<long long, int> preSum;
    int dfs(TreeNode* node, long long cur, int targetSum) {
        if (!node) return 0;
        cur += node->val;
        int res = 0;
        if (preSum.contains(cur - targetSum)) {
            res += preSum[cur - targetSum];
        }
        ++preSum[cur];
        res += dfs(node->left, cur, targetSum);
        res += dfs(node->right, cur, targetSum);
        --preSum[cur];
        return res;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        preSum[0] = 1;
        return dfs(root, 0, targetSum);
    }
};


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}