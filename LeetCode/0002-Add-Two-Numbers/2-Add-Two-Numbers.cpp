/*
LeetCode 2: Add Two Numbers
@Description:
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0
itself.

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/
#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/*
思路：

*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode();
		ListNode* node = head;
		int sum = 0, c = 0;
		while ((l1 != nullptr) && (l2 != nullptr)) {
			sum = l1->val + l2->val + c;
			head->val = sum % 10;
			c = sum / 10;
			head->next = new ListNode();
			head = head->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1) {
			sum = c + l1->val;
			head->val = sum % 10;
			c = sum / 10;
			head->next = new ListNode();
			head = head->next;
			l1 = l1->next;
		}
		while (l2) {
			sum = c + l2->val;
			head->val = sum % 10;
			c = sum / 10;
			head->next = new ListNode();
			head = head->next;
			l2 = l2->next;
		}
		if (c)
			head->val = 1;
		else
			head = nullptr;
		return node;
	}
	//简化版：从下一个 node 节点开始 push 值
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *head = nullptr, *node = nullptr;
		int sum = 0, c = 0;
		while (l1 || l2) {
			int n1 = l1 ? l1->val : 0;
			int n2 = l2 ? l2->val : 0;
			sum = n1 + n2 + c;
			if (!node)
				head = node = new ListNode(sum % 10);
			else {
				node->next = new ListNode(sum % 10);
				node = node->next;
			}
			c = sum / 10;
			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;
		}
		if (c > 0)
			node->next = new ListNode(c);
		return head;
	}
};
int main() { return 0; }