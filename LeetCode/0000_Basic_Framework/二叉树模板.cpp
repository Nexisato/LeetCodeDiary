//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
void print(vector<vector<int>> res) {
    for (int i = 0; i < res.size(); i++) {
        vector<int> tmp = res[i];
        for (int j = 0; j < tmp.size(); j++) {
            cout << tmp[j] << " ";
        }
        cout << "\n";
    }
}