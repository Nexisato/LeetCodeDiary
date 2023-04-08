#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};
/**
 * @brief 
 * 自右向左层序遍历
 * 
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int res = root->val;
        for (queue q{deque { root }}; q.size(); q.pop()) {
            auto [val, lnode, rnode] = *q.front();
            if (rnode) q.push(rnode);
            if (lnode) q.push(lnode);
            res = val;
        }
        return res;
    }
};
int main() {

    return 0;
}