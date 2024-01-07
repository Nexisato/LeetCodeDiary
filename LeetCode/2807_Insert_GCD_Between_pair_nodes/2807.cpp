/*
 * @Date: 2024-01-06 09:16:59
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2807_Insert_GCD_Between_pair_nodes/2807.cpp
 * /LeetCodeDiary/LeetCode/2807_Insert_GCD_Between_pair_nodes/2807.cpp
 * @Description:
 */
#include <iostream>
#include <vector>

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
    int gcd(int a, int b) {
        int m = std::max(a, b), n = std::min(a, b);
        if (n == 0)
            return m;
        int z = n;
        while (m % n != 0) {
            z = m % n;
            m = n;
            n = z;
        }
        return z;
    }
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head) {
        ListNode *cur = head, *post = head->next;
        ListNode *pre = nullptr, *tmpNode = nullptr;
        while (post) {
            int gVal = gcd(cur->val, post->val);
            pre = cur;
            pre->next = new ListNode(gVal);
            tmpNode = pre->next;
            tmpNode->next = post;
            cur = post;
            post = post->next;
        }
        return head;
    }
};
int main() { return 0; }