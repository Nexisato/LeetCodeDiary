/*
Description:
Serialization is the process of converting a data structure or object into a sequence of bits so that
it can be stored in a file or memory buffer, or transmitted across a network connection link
to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree.
There is no restriction on how your serialization/deserialization algorithm should work.
You just need to ensure that
a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree.
You do not necessarily need to follow this format, so please be creative and come up with different approaches
yourself.
*/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {

public:
	// Encodes a tree to a single string.
	//基本思路：BFS,二叉树的层序遍历
	string serialize(TreeNode* root) {
		string serial = "[]";
		if (root == nullptr)
			return serial;
		queue<TreeNode*> q;
		q.push(root);
		serial = "[ ";
		while (!q.empty()) {
			TreeNode* node = q.front();
			q.pop();
			if (node) {
				serial += to_string(node->val) + " ";
				q.push(node->left);
				q.push(node->right);
			} else {
				serial += "null ";
			}
		}
		serial += "]";
		return serial;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		data.erase(0, data.find_first_not_of("[")); //保证输出的字符串序列不出现0值
		data.erase(data.find("]"));
		if (data.size() == 0)
			return nullptr;
		vector<TreeNode*> result;
		istringstream input(data);
		string info;
		while (input >> info) {
			if (info == "null") {
				result.push_back(nullptr);
			} else {
				result.push_back(new TreeNode(atoi(info.c_str())));
			}
		}
		//根据BFS序列还原二叉树
		int pos = 1;
		for (int i = 0; pos < result.size(); ++i) {
			if (!result[i])
				continue;
			result[i]->left = result[pos++];
			if (pos < result.size())
				result[i]->right = result[pos++];
		}
		return result[0];
	}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
int main() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(3);
	root->right = new TreeNode(5);
	TreeNode* test = nullptr;
	Codec cc, dd;
	TreeNode* tmp = dd.deserialize(cc.serialize(root));
	cout << cc.serialize(root);
	cout << cc.serialize(tmp);
	return 0;
}