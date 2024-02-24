/*
 * @Date: 2024-02-23 09:56:41
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2583-Kth-Largest-Sum-of-Binary-Tree/2583.cpp
 * @Description:
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            long long sum = 0;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (minHeap.size() < k) {
                minHeap.push(sum);
            } else if (sum > minHeap.top()) {
                minHeap.pop();
                minHeap.push(sum);
            }
        }
        return minHeap.size() == k ? minHeap.top() : -1;
    }
};

int main() {

    return 0;
}