/*
LeetCode 203: Remove Linked List Elements
@Description:
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has 
Node.val == val, and return the new head.

Constraints:
The number of nodes in the list is in the range [0, 10^4].
1 <= Node.val <= 50
0 <= k <= 50
*/
#include <iostream>
#include <vector>
#include <unordered_map>
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
思路：签到题
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *virnode = new ListNode(-1);
        virnode->next = head;
        ListNode *node = virnode;
        while (node->next != nullptr) {
            if (node->next->val == val) {
                ListNode *tmp = node;
                while (node->next && node->next->val == 1)
                    node = node->next;
                tmp->next = node->next;
            }
            else {
                node = node->next;
            }
        }
        return virnode->next;
    }
};

int main() {

    return 0;
}