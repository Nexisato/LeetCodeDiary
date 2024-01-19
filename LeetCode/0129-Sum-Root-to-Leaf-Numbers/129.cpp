/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0129_Sum_Root_to_Leaf_Numbers/129.cpp
 * @Description: 
 */
/*
LeetCode 129: Sum Root to Leaf Numbers
@Description:
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers.

A leaf node is a node with no children.

Constraints:
The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
思路：DFS
遍历到叶子节点时，记录一个数值
遍历到非叶子节点，保存数值
*/
class Solution {
private:
    int res = 0, tmp = 0;
    void dfs(TreeNode* node) {
        if (!node)
            return;
        tmp = tmp * 10 + node->val;
        if (!node->left && !node->right) {
            res += tmp;
            tmp /= 10;
            return;
        }
        dfs(node->left);
        dfs(node->right);
        tmp /= 10;
    }
public:
    int sumNumbers(TreeNode* root) {
        dfs(root);
        return res;
    }
};
int main() {
    TreeNode* root = new TreeNode(4, new TreeNode(9), new TreeNode(0));
    TreeNode* l = root->left;
    l->left = new TreeNode(5);
    l->right = new TreeNode(1);
    Solution ss;
    cout << ss.sumNumbers(root) << endl;
    return 0;
}