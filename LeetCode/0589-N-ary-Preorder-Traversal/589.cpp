#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            res.push_back(node->val);
            for (int i = node->children.size() - 1; i >= 0; i--) {
                st.push(node->children[i]);
            }
        }

        return res;
    }
};
int main() {

    return 0;
}