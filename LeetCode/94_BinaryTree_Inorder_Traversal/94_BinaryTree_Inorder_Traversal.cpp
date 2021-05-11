/*
Description:
Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

 // Definition for a binary tree node.
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> tmp;
        vector<int> outputs;
        TreeNode* node=root;
        while(node!=nullptr||!tmp.empty()){
            if(node!=nullptr){
                tmp.push(node);
                node=node->left;
            }else{
                node=tmp.top();
                tmp.pop();
                outputs.push_back(node->val);
                //tmp.push(node->right);
                node=node->right;
            }
        }
        return outputs;
    }
};
int main(){

    return 0;
}