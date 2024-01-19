#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * @brief 
 * 
 * 
 */
class Solution {
private:
    int traversal(TreeNode* node, int minVal, int maxVal) {
        if (!node) return 0;
        int diff = max(abs(node->val - minVal), abs(node->val - maxVal));

        minVal = min(minVal, node->val);
        maxVal = max(maxVal, node->val);

        int lDiff = traversal(node->left, minVal, maxVal);
        int rDiff = traversal(node->right, minVal, maxVal);

        diff = max(diff, max(lDiff, rDiff));
        return diff;
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        return traversal(root, root->val, root->val);
    }
};
int main() {

    return 0;
}