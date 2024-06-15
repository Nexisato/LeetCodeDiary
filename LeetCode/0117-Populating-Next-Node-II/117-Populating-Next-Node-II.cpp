/*
Description:
Given a binary tree
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be
set to NULL. Initially, all next pointers are set to NULL.

Follow up:
You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
	//思路：非递归利用队列进行层序遍历，可以得到与116相同的结果（不管是否是完全二叉树）
	Node* connect(Node* root) {
		queue<Node*> que;
		if (root)
			que.push(root);
		while (!que.empty()) {
			int size = que.size();
			Node* node;
			Node* nodePre;
			for (int i = 0; i < size; i++) {
				if (i == 0) {
					nodePre = que.front();
					que.pop();
					node = nodePre;
				} else {
					node = que.front();
					que.pop();
					nodePre->next = node;
					nodePre = node;
				}
				if (node->left)
					que.push(node->left);
				if (node->right)
					que.push(node->right);
			}
			node->next = NULL;
		}
		return root;
	}
};

int main() { return 0; }