/*
Description:
Write a function to delete a node in a singly-linked list.

You will not be given access to the head of the list,
instead you will be given access to the node to be deleted directly.

It is guaranteed that the node to be deleted is not a tail node in the list.

*/
#include <algorithm>
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode* p = node;
		ListNode* pforward = p;
		while (p->next != NULL) {
			p->val = p->next->val;
			pforward = p;
			p = p->next;
		}
		pforward->next = NULL;
	}
};
int main() {
	Solution ss;

	return 0;
}