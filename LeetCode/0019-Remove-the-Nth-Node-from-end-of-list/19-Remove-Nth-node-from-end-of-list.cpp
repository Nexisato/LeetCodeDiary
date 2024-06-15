/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0019-Remove-the-Nth-Node-from-end-of-list/19-Remove-Nth-node-from-end-of-list.cpp
 * @Description:
 */
/*
Description:
Given the head of a linked list,
remove the nth node from the end of the list and return its head.
Follow up: Could you do this in one pass?
Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	// 思路：双指针；建立fastPtr和slowPtr，fastPtr先移动n步，然后二者一起开始移动
	// 直到fastPtr指向链表尾部，这样只需遍历一次链表
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head)
			return nullptr;
		ListNode* virnode = new ListNode(0);
		n = n + 1;
		virnode->next = head;
		ListNode *fastNode = virnode, *slowNode = virnode;
		while ((fastNode != nullptr) && (n--)) {
			fastNode = fastNode->next;
		}
		while (fastNode != nullptr) {
			fastNode = fastNode->next;
			slowNode = slowNode->next;
		}
		slowNode->next = slowNode->next->next;
		return virnode->next; // 此处很关键，若只有一个节点，删除1个节点后链表为空，因此不能return
		                      // head
	}
	ListNode* removeNthFromEnd_cur(ListNode* head, int n) {
		ListNode* virHead = new ListNode(-1, head);
		ListNode *node = virHead, *cur = nullptr;
		while (node && (n--))
			node = node->next;
		cur = virHead;
		ListNode* prev = nullptr;
		while (node) {
			node = node->next;
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		delete cur;
		return virHead->next;
	}
	void Print(ListNode* head) {
		ListNode* p = head;
		while (p != nullptr) {
			cout << p->val << "  ";
			p = p->next;
		}
	}
};

int main() {
	ListNode* head = new ListNode(1);
	ListNode* p = head;
	/* for(int i=0;i<4;i++){
	     ListNode*q=new ListNode(i+2);
	     p->next=q;
	     p=q;
	 }*/
	p->next = nullptr;
	Solution ss;
	ss.Print(head);
	ss.removeNthFromEnd(head, 1);
	ss.Print(head);
	return 0;
}
