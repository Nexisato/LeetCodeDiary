/*
LeetCode: 108
Description:
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which 
the depth of the two subtrees of every node never differ by more than 1.
*/
#include<bits/stdc++.h>
using namespace std;
/*
思路：
1. 二分 ，遍历
*/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
private:
    TreeNode* traversal(vector<int>& nums, int l, int r) {
        if (!nums.size() || l > r) return nullptr;
        int mid = (l + r) / 2; // int mid = l + ((r - l) / 2);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traversal(nums, l, mid - 1);
        root->right = traversal(nums, mid + 1, r);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        return traversal(nums, l, r);
    }
};
int main() {

    return 0;
}