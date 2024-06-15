/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0025-Reverse-Nodes-in-K-Group/25-Reverse-Nodes-in-K-Group.cpp
 * @Description:
 */
/*
LeetCode: 25 Reverse Nodes in K Group
Description:
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Follow up:
Could you solve the problem in O(1) extra memory space?
You may not alter the values in the list's nodes, only nodes itself may be changed.

Constraints:
The number of nodes in the list is in the range sz.
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz
*/
#include <iostream>
#include <vector>
using namespace std;

/*
思路：

*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
	ListNode* reverse_tmp(ListNode* a, ListNode* b) { //[a, b)
		ListNode *node = a, *prenode = nullptr, *postnode = a;
		while (node != b) {
			postnode = node->next;
			node->next = prenode;
			prenode = node;
			node = postnode;
		}
		return prenode;
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head)
			return nullptr;
		ListNode *begin = head, *end = head;
		for (int i = 0; i < k; i++) {
			if (end == nullptr)
				return head;
			end = end->next;
		}
		ListNode* newHead = reverse_tmp(begin, end);
		begin->next = reverseKGroup(end, k);
		return newHead;
	}
	ListNode* reverseKGroup_iter(ListNode* head, int k) {
		int length = 0;
		ListNode* node = head;
		while (node) {
			++length;
			node = node->next;
		}
		ListNode *cur = head, *prev = nullptr, *post = nullptr;
		ListNode* virNode = new ListNode(-1, head);
		prev = virNode;
		ListNode *tail = cur, *concat = prev;
		for (; length >= k; length -= k) {
			for (int i = 0; i < k; ++i) {
				post = cur->next;
				cur->next = prev;
				prev = cur;
				cur = post;
			}
			concat->next = prev;
			tail->next = cur;
			concat = tail;
			tail = cur;
		}
		return virNode->next;
	}
};
int main() { return 0; }