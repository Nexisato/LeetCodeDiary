#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/*
不可能在相交点后存在分叉，否则代表着 next 指针存在两个
*/
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		ListNode *node1 = headA, *node2 = headB;
		while (node1 != node2) {
			node1 = (node1 != nullptr)
			            ? (node1->next)
			            : headB; //相当于走到头，补足差距，换路，最多走 len1 + len2 次
			node2 = (node2 != nullptr) ? (node2->next) : headA;
		}
		return node1;
	}
};
int main() { return 0; }