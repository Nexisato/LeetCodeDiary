/*
Chapter 0：学习算法和刷题的框架思维
*/

// 1. 数组遍历框架
void traverse(int arr[], int size){
    for(int i = 0; i < size; i++){
        //迭代访问 arr[i]
    }
}

//2. 链表遍历框架
/*基本单链表节点*/
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void traverse(LNode *head){
    for(LNode *p = head; p! = nullptr; p = p->Next){
        //迭代访问 p->Data
    }
}

void traverse(LNode *head){
    if(head==nullptr)
        return;
    traverse(head->Next);
    //递归访问
}

//3.二叉树遍历框架
/*基本二叉树节点——链式存储*/ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void PreOrderTraversal(BinTree BT){
    if(BT){
        /*Operation*/
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}
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

//中序遍历
void InOrderTraversal(BinTree BT){
    if(BT){
        InOrderTraversal(BT->Left);
        /*Operation*/
        InOrderTraversal(BT->Right);
    }
}
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
//后序遍历
void PostOrderTraversal(BinTree BT){
    if(BT){
        PostOrderTraversal(BT->Left);
        PostOrderTraversal(BT->Right);
        /*Operation*/
    }
}
 void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);    // 中
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }


//层序遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL);
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> outputs;
        if(root!=nullptr) q.push(root);
        while(!q.empty()){
            vector<int> tmp;
            int size=q.size();
            for(int i=0;i<size;++i){
                TreeNode *node=q.front();
                tmp.push_back(node->val);
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            outputs.push_back(tmp);
        }
        return outputs;
        
    }
};

	