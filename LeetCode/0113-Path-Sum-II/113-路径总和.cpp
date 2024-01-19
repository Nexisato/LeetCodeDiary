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
private:
    vector<vector<int>> outputs;
    vector<int> tmp;
public:
    void preOrder(TreeNode* node, int sum){
        if(!node) return;
        tmp.push_back(node->val);
        sum-=node->val;
        if(sum==0&&!node->left&&!node->right){  //叶节点路径判断
            outputs.push_back(tmp);
        }
        if(node->left) preOrder(node->left,sum);
        if(node->right) preOrder(node->right,sum);
        tmp.pop_back();//回溯前先弹出当前节点
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return {};
        preOrder(root,sum);
        return outputs;

    }
};