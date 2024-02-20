/*
 * @Date: 2024-02-19 08:30:27
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0590-N-ary-Postorder-Traversal/590.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            res.push_back(node->val);
            for (auto& child : node->children) {
                st.push(child);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main() {

    return 0;
}

