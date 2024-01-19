#include <bits/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * @brief 
 * 单调栈
 * 维护一个非递增的单调栈，若遇到大于栈顶的元素，则一直pop，直到栈保持非递增
 * pop 出的节点对应的数组位置值即为遇到的节点对应的val
 * 
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* node = head;
        int n = 0;
        unordered_map<ListNode*, int> table;
        while (node) {
            table[node] = n;
            ++n;
            node = node->next;
        }
        
        vector<int> res(n, 0);
        vector<ListNode*> st;
        st.push_back(head);
        node = head->next;
        while (node) {
            if (node->val <= st.back()->val) {
                st.push_back(node);
            } else {
                while (!st.empty() && st.back()->val < node->val) {
                    ListNode *top = st.back();
                    res[table[top]] = node->val;
                    st.pop_back();
                }
                st.push_back(node);
            }
            node = node->next;
        }
        return res;
    }

    vector<int> nextLargerNodes_no_extra_space(ListNode* head) {
        vector<int> res;
        vector<pair<int, int>> st; //first 记录 val, second 记录 idx，遍历一次即可

        ListNode* node = head;
        int idx = -1;
        while (node) {
            ++idx;
            res.push_back(0);
            while (!st.empty() && st.back().first < node->val) {
                int topIdx = st.back().second;
                res[topIdx] = node->val;
                st.pop_back();                
            }
            st.push_back({node->val, idx});
            node = node->next;
        }

        return res;
    }
};
int main() {


    return 0;
}