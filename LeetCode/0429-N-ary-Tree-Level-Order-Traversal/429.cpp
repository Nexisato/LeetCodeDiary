/*
 * @Date: 2024-02-17 15:45:25
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0429-N-ary-Tree-Level-Order-Traversal/429.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<Node*> q;
        vector<int> level;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            level = std::move(vector<int>());
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);
                for (auto& child : node->children) {
                    q.push(child);
                }
            }
            res.push_back(level);
        }

        return res;
    }
};
int main() {

    return 0;
}