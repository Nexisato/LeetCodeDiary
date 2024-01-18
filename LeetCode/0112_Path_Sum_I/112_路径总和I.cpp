/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL) return false;
        if(root->left==NULL&&root->right==NULL) return (sum==root->val)?true:false;
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
    }
    bool hasPathSum_full(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right) return (targetSum == root->val) ? true : false;
        
        if (root->left) {
            targetSum -= root->val;
            if (hasPathSum(root->left, targetSum)) return true;
            targetSum += root->val;
        }
        if (root->right) {
            targetSum -= root->val;
            if (hasPathSum(root->right, targetSum)) return true;
            targetSum += root->val;
        }
        return false;
    }
};