/*
LeetCode 160: Intersection of Two Linked Lists
@Description:
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:

Constraints:
The number of nodes of listA is in the m.
The number of nodes of listB is in the n.
0 <= m, n <= 3 * 10^4
1 <= Node.val <= 10^5
0 <= skipA <= m
0 <= skipB <= n
intersectVal is 0 if listA and listB do not intersect.
intersectVal == listA[skipA + 1] == listB[skipB + 1] if listA and listB intersect.
 

Follow up: Could you write a solution that runs in O(n) time and use only O(1) memory?
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
1. set哈希集合
2. 双指针
*/
// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		ListNode *nodeA = headA, *nodeB = headB;
		unordered_set<ListNode*> record;
		while (nodeA != nullptr) {
			record.insert(nodeA);
			nodeA = nodeA->next;
		}
		while (nodeB != nullptr) {
			if (record.count(nodeB))
				return nodeB;
			nodeB = nodeB->next;
		}
		return nullptr;
	}
	/*
	双指针：设链表长度分别为m, n，公共部分长为c
	m = a + c; n = b + c
	两者最多移动a + c + b次，即可找到公共节点
	*/
	ListNode* getIntersectionNode_doubleptr(ListNode* headA, ListNode* headB) {
		ListNode *nodeA = headA, *nodeB = headB;
		if (!nodeA || !nodeB)
			return nullptr;
		while (nodeA != nodeB) {
			nodeA = (nodeA == nullptr) ? headB : nodeA->next;
			nodeB = (nodeB == nullptr) ? headA : nodeB->next;
		}
		return nodeA;
	}
};
int main() { return 0; }