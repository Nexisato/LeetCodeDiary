#include <iostream>
#include <vector>
#include <functional>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int res = 0;
        function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode* node) -> pair<int, int> {
            if (!node) return {0, 0};
            auto [nodes_left, coins_left] = dfs(node->left);
            auto [nodes_right, coins_right] = dfs(node->right);
            int nodes_cur = nodes_left + nodes_right + 1;
            int coins_cur = coins_left + coins_right + node->val;
            res += abs(coins_cur - nodes_cur);  // 计算每颗子树的移动次数
            return {nodes_cur, coins_cur};
        };

         dfs(root);

        return res;

    }
};
int main() { return 0; }