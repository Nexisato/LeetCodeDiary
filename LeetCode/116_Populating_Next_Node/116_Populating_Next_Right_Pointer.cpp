/*
Description:
You are given a perfect binary tree where all leaves are on the same level, 
and every parent has two children. The binary tree has the following definition:
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Follow up:
You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 
*/
#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {

private:
//递归思路：注意分析单层逻辑
    void traversal(Node* cur){
        if(!cur) return;
        //完全二叉树，有左子节点必有右子节点
        if(cur->left) cur->left->next=cur->right;
        if(cur->right){
            if(cur->next) cur->right->next=cur->next->left;
            else cur->right->next=NULL;
        }
        traversal(cur->left);
        traversal(cur->right);
    }
public:
    //思路：利用二叉树层序遍历方法
    //构造队列存储二叉树的节点，再用一个vector容器存放每一层的二叉树节点，遍历这个容器即可将所有相邻节点连接起来
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*> q;
        root->next=NULL;
        if(!root->left&&!root->right)
            return root;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            int size=q.size();
            vector<Node*> layer;
            for(int i=0;i<size;i++){
                Node *tmp=q.front();
                layer.push_back(tmp);
                q.pop();
                if(tmp->left)q.push(tmp->left);
                if(tmp->right)q.push(tmp->right);
            }
            int layer_index=0;
            for(;layer_index<layer.size()-1;layer_index++){
                layer[layer_index]->next=layer[layer_index+1];
            }
            layer[layer_index]->next=NULL;
        }
        return root;
    }
    //层序遍历2：利用链表替代vector进行单层访问，节省空间
    Node * connect_1(Node* root){
        queue<Node*> que;
        if(root) que.push(root);
        while(!que.empty()){
            int size=que.size();
            Node *node;
            Node* nodePre;
            for(int i=0;i<size;i++){
                node = que.front();
                que.pop();
                if (i!=0) {
                    nodePre->next = node;
                    nodePre = node;
                }
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            node->next=NULL;
        }
        return root;
    }
};

int main(){

    return 0;
}
