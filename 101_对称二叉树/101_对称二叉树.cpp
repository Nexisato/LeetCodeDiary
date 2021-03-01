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
    bool compare(TreeNode *l,TreeNode* r){
        if(l==NULL&&r==NULL) return true;
        else if(l==NULL&&r!=NULL) return false;
        else if(l!=NULL&&r==NULL) return false;
        else if(l->val!=r->val) return false;
        else return compare(l->left,r->right)&&compare(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return compare(root->left,root->right);

    }
};