/*
剑指Offer 22: 链表中倒数第 k 个节点
@Description:
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是
1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。
*/
#include <algorithm>
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
class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode *fastPtr, *slowPtr;
		int N = 1;
		fastPtr = head;
		while (fastPtr != nullptr) {
			fastPtr = fastPtr->next;
			++N;
		}
		int count = N - K;
		slowPtr = head;
		while (--count)
			slowPtr = slowPtr->next;
		return slowPtr;
	}
};
int main() { return 0; }