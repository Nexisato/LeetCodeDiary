/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0083_Remove_Duplicates_from_Sorted_List/83_Remove_Duplicates_from_Sorted_List.cpp
 * @Description:
 */
/*
LeetCode 83: Remove Duplicates from Sorted List
@Description:
Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
Return the linked list sorted as well.

Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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
类似于82，注意是否保留重复元素
*/
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next)
			return head;
		ListNode *virNode = new ListNode(101, head), *node = virNode;
		while (node && node->next) {
			if (node->val == node->next->val) {
				int num = node->val;
				while (node->next && node->next->val == num)
					node->next = node->next->next;
			}
			node = node->next;
		}
		return virNode->next;
	}
	ListNode* deleteDuplicates_node(ListNode* head) {
		if (!head)
			return nullptr;
		ListNode *cur = head, *post = cur->next;
		ListNode* tmp = nullptr;
		while (cur->next) {
			int curVal = cur->val;
			if (post->val == curVal) {
				while (post && post->val == curVal) {
					tmp = post;
					post = post->next;
					delete tmp;
				}
				cur->next = post;
			} else {
				cur = post;
				post = post->next;
			}
		}
		return head;
	}
};
int main() { return 0; }