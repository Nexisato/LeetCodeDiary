/*
 * @Date: 2024-02-02 15:22:45
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0148-Sort-List/148.cpp
 * @Description: 
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *virHead = new ListNode(-1);
        ListNode *cur = virHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return virHead->next;
    }
    ListNode *mergeSort(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr;
        ListNode *left = mergeSort(head);
        ListNode *right = mergeSort(mid);
        return merge(left, right);
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
int main() { return 0; }