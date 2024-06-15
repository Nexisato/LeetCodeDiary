/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0141-linked-list-cycle/141-linked-list-cycle.cpp
 * @Description:
 */
/*
Description:
LeetCode: 141
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list
that can be reached again by continuously following the next pointer.
Internally, pos is used to denote the index of the node that tail's next pointer is connected to. 
Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Constraints:
The number of the nodes in the list is in the range [0, 10^4].
-10^5 <= Node.val <= 10^5
pos is -1 or a valid index in the linked-list.

Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};
/*
思路：双指针，Floyd判圈算法
1. 假设有两个指针slowPtr和fastPtr
2. fastPtr每次移动两步，slowPtr每次移动一步，则fastPtr会先于slowPtr进入环
3. 两个指针在环内移动时，由于速度差必定在某一时刻相遇
*/
class Solution {
public:
	bool hasCycle(ListNode* head) {
		if (!head || !head->next)
			return false;
		ListNode *slowPtr = head, *fastPtr = head->next;
		while (slowPtr != fastPtr) {
			if (!fastPtr || !fastPtr->next)
				return false;
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next->next;
		}
		return true;
	}
};
int main() { return 0; }