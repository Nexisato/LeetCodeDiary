/*
LeetCode 173: Binart Search Tree Iterator
@Description:
Implement the BSTIterator class that represents an iterator over the in-order traversal of a 
binary search tree (BST):
BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. 
The root of the BST is given as part of the constructor. The pointer should be initialized 
to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, 
otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, 
the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number 
in the in-order traversal when next() is called.

Constraints:
The number of nodes in the tree is in the range [1, 10^5].
0 <= Node.val <= 10^6
At most 10^5 calls will be made to hasNext, and next.
 
Follow up:
Could you implement next() and hasNext() to run in average O(1) time and 
use O(h) memory, where h is the height of the tree?
*/
#include <bits/stdc++.h>
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
思路：开个数组存放中序遍历序列，再根据数组实现
*/
class BSTIterator {
private:
    vector<int> inOrderNums;
    int index, n;
    void traversal(TreeNode *root) {
        if (!root) return;
        traversal(root->left);
        inOrderNums.emplace_back(root->val);
        traversal(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        inOrderNums.clear();
        index = 0;
        traversal(root);
        n = inOrderNums.size();
    }
    
    int next() {
        return inOrderNums[index++];
    }
    
    bool hasNext() {
        return (index < n);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
int main() {

    return 0;
}