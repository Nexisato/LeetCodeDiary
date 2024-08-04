#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool isSame(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        else if (!t1 || !t2) return false;
        else if (t1->val != t2->val) return false;

        return isSame(t1->left, t2->left) && isSame(t1->right, t2->right);

    }
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (!root && !subRoot) return true;
        else if (!root || !subRoot) return false;
        else if (isSame(root, subRoot)) return true;
        else return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
int main() { return 0; }