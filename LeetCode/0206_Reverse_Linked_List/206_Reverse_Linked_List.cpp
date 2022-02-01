/*
Description:
Reverse a singly linked list.
*/
#include<bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 /*
 思路：记录 => 反转 => 移动
 1. 标记三个node: prenode , node , postnode
 2. postnode 先保存 node 指向的下一个节点，再将 node 指向 prenode
 3. 将 prenode 和 node 同时后移
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode *node = head , *prenode = nullptr , *postnode = head;
        while (node) {
            postnode = node -> next;
            node -> next = prenode;
            prenode = node;
            node = postnode;
        }
        head = prenode;
        return head;
    }
};

int main (){

    return 0;
}