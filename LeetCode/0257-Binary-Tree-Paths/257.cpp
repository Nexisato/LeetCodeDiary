#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * @brief 
 * 
 * 
 */
class Solution {
private:
    vector<string> res;
    void traversal(TreeNode* node, vector<int>& path, vector<string>& res) {
        path.push_back(node->val);
        if (!node->left && !node->right) {
           string sPath = "";
           for (int i = 0; i < path.size() - 1; ++i) {
            sPath += to_string(path[i]);
            sPath += "->";
           }
           sPath += to_string(path[path.size() - 1]);
           res.push_back(sPath);
           return; 
        }
        if (node->left) {
            traversal(node->left, path, res);
            path.pop_back();
        }
        if (node->right) {
            traversal(node->right, path, res);
            path.pop_back();
        }
    }
    void traversal_sim(TreeNode *node, string path, vector<string>& res) {
        path += to_string(node->val);
        if (!node->left && !node->right) {
            res.push_back(path);
            return;
        }
        if (node->left) traversal(node->left, path + "->", res);
        if (node->right) traversal(node->right, path + "->", res);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        res.clear();
        if (!root) return res;
        vector<int> path;
        traversal(root, path, res);
        return res;
    }
};
int main() {


    return 0;
}