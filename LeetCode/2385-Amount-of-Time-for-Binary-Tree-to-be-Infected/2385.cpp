#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//  Definition for a binary tree node.
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
public:
    int amountOfTime(TreeNode* root, int start) {
        const int MAX = 1e+5 + 1;
        TreeNode* parent[MAX] = {nullptr};
        TreeNode* begin_node = nullptr;
        function<void(TreeNode*, TreeNode*)> dfs = [&](TreeNode* node,
                                                       TreeNode* from) {
            if (!node) return;
            parent[node->val] = from;
            if (node->val == start) begin_node = node;
            dfs(node->left, node);
            dfs(node->right, node);
        };
        dfs(root, nullptr);

        function<int(TreeNode*, TreeNode*)> maxDistance =
            [&](TreeNode* node, TreeNode* from) -> int {
            if (!node) return -1;
            int res = -1;
            if (node->left != from)
                res = max(res, maxDistance(node->left, node));
            if (node->right != from)
                res = max(res, maxDistance(node->right, node));
            if (parent[node->val] != from)
                res = max(res, maxDistance(parent[node->val], node));

            return res + 1;
        };

        return maxDistance(begin_node, begin_node);
    }
};

int main() { return 0; }