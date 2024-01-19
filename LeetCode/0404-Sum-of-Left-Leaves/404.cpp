#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 0;
        int leftVal = sumOfLeftLeaves(root->left);
        if (root->left && !root->left->left && !root->left->right) {
            leftVal += root->left->val;
        }
        int rightVal = sumOfLeftLeaves(root->right);
        return leftVal + rightVal;
    }
};
int main() {

    return 0;
}