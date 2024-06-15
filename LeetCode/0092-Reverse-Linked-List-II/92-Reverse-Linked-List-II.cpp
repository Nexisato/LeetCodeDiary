/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0092-Reverse-Linked-List-II/92-Reverse-Linked-List-II.cpp
 * @Description:
 */
/*
LeetCode: 92 Reverse Linked List II
Description:
Reverse a linked list from position m to n. Do it in one-pass.
Note: 1 ≤ m ≤ n ≤ length of list.
*/
#include <iostream>
#include <vector>
using namespace std;
/*
思路：
递归解法：
1. 递归翻转整个链表
2. 反转链表前 N 个节点
3. 递归反转区间 [m , n]中的节点

迭代解法：

*/
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode* ptr) : val(x), next(ptr) {}
};

class Solution {
private:
	ListNode* reverse_whole(ListNode* head) {
		if (head->next == nullptr)
			return head;
		ListNode* last = reverse_whole(head->next);
		head->next->next = head;
		head->next = nullptr;
		return last;
	}
	ListNode* successor = nullptr;
	ListNode* reverse_preK(ListNode* head, int K) {
		if (K == 1) {
			successor = head->next;
			return head;
		}
		ListNode* last = reverse_preK(head->next, K - 1);
		head->next->next = head;
		head->next = successor;
		return last;
	}

public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == 1)
			return reverse_preK(head, n);
		head->next = reverseBetween(head->next, m - 1, n - 1);
		return head;
	}
	ListNode* reverseBetween_iter(ListNode* head, int left, int right) {
		if (!head->next || right == 1)
			return head;
		ListNode* virNode = new ListNode(-1, head);
		ListNode *pre = virNode, *cur = head, *post = nullptr;
		while (left > 1 && cur) {
			pre = cur;
			cur = cur->next;
			--left;
			--right;
		}
		ListNode *tail = cur, *concat = pre;
		while (right--) {
			post = cur->next;
			cur->next = pre;
			pre = cur;
			cur = post;
		}
		concat->next = pre;
		tail->next = cur;
		concat = tail;
		;
		return virNode->next;
	}
};
int main() { return 0; }