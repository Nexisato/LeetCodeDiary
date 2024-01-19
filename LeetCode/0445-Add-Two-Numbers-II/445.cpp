#include <iostream>
#include <vector>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*基本单链表节点*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* reverse(ListNode *root) {
        ListNode *pre = nullptr, *cur = nullptr, *post = nullptr;
        cur = root;
        while (cur) {
            post = cur->next;
            cur->next = pre;
            pre = cur;
            cur = post;
        }
        root = pre;
        return root;
    }
    ListNode *addList(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *node = nullptr;
        int sum = 0, c = 0;
        while (l1 || l2) {
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            sum = num1 + num2 + c;
            if (!node) 
                head = node = new ListNode(sum % 10);
            else {
                node->next = new ListNode(sum % 10);
                node = node->next;
            }
            c = sum / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (c)
            node->next = new ListNode(c);
        return head;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode *res = addList(l1, l2);
        res = reverse(res);
        return res;
    }
};

int main() {

    return 0;
}