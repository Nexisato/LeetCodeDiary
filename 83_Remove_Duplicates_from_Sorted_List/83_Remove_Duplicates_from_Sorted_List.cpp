/*
LeetCode 83: Remove Duplicates from Sorted List
@Description:
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.

Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
思路：
类似于82，注意是否保留重复元素
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *virNode = new ListNode(101, head), *node = virNode;
        while (node && node->next) {
            if (node->val == node->next->val) {
                int num = node->val;
                while (node->next && node->next->val == num) 
                    node->next = node->next->next;
            }
            node = node->next;
        }
        return virNode->next;
    }
};
int main() {


    return 0;
}