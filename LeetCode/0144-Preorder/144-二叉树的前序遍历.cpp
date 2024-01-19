/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> outputs;
        stack<TreeNode*> tmp;
        tmp.push(root);
        while(!tmp.empty()){
            TreeNode* node=tmp.top();
            tmp.pop();
            if(node!=nullptr) 
                outputs.push_back(node->val);
            else continue;
            tmp.push(node->right);
            tmp.push(node->left);
        }
        return outputs;
    }
};