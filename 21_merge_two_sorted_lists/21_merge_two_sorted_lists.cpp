/*
Description:
Merge two sorted linked lists and return it as a new sorted list. 
The new list should be made by splicing together the nodes of the first two lists.

Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.
*/
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

/*
思路：常规 merge 操作
notes: 不需要另外建立链表，在原有链表节点的基础上进行移位置操作即可
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *prel = new ListNode(-1); //sentinel node for returning
        ListNode *p = prel;
        /*
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                p->val = p1->val;
                p1 = p1->next;
            }else{
                p->val = p2->val;
                p2 = p2->next;
            }
            p->next = new ListNode();
            p = p->next;
        }
        if (p1) p = p1;
        else if (p2) p = p2;
        else p = nullptr;
        return l;*/
        while (l1 && l2){
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = (l1 == nullptr) ? l2 : l1;
        return prel->next;    
    }
};
int main() {

    return 0;
}