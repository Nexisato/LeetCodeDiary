/*
 * @Date: 2024-01-22 09:21:17
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0199-Binary-Tree-Right-View/199.cpp
 * @Description:
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
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
	vector<int> rightSideView(TreeNode* root) {
		if (!root)
			return vector<int>();
		vector<int> res;
		TreeNode* node = root;
		queue<TreeNode*> q;
		q.push(node);

		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				node = q.front();
				q.pop();
				if (i == size - 1)
					res.push_back(node->val);
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
		}
		return res;
	}
};
int main() { return 0; }