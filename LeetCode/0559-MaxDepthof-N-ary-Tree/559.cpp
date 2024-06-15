#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) { val = _val; }

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	int maxDepth(Node* root) {
		if (!root)
			return 0;
		int maxD = 0;
		for (int i = 0; i < root->children.size(); ++i) {
			maxD = max(maxD, maxDepth(root->children[i]));
		}
		return 1 + maxD;
	}
};

int main() { return 0; }