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
    // 中点 -> 反转 -> 合并
    ListNode *median(ListNode *node) {
        ListNode *slow = node, *fast = node;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *node) {
        ListNode *prev = nullptr, *cur = node, *post = node->next;
        while (cur) {
            post = cur->next;
            cur->next = prev;
            prev = cur;
            cur = post;
        }
        return prev;
    }

    ListNode *merge(ListNode *node1, ListNode *node2) {
        ListNode *virNode = new ListNode(-1);
        ListNode *cur = virNode;
        int count = 0;
        while (node1 && node2) {
            if (count % 2 == 0) {
                cur->next = node1;
                node1 = node1->next;
            } else {
                cur->next = node2;
                node2 = node2->next;
            }
            ++count;
            cur = cur->next;
        }
        cur->next = (node1) ? node1 : node2;
        return virNode->next;
    }

public:
    void reorderList(ListNode *head) {
        if (!head->next) return;
        ListNode *l = head;
        ListNode *mid = median(head);
        ListNode *r = mid->next;
        mid->next = nullptr;
        r = reverse(r);
        merge(l, r);
    }
};

int main() { return 0; }