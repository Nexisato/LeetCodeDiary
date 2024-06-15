/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0142-Linked-List-Cycle-II/142.cpp
 * @Description:
 */
#include <iostream>
#include <string>
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
	ListNode* detectCycle(ListNode* head) {
		ListNode *fastNode = head, *slowNode = head;
		while (fastNode != nullptr && fastNode->next != nullptr) { //这里的 && 条件不可改为 ||，移动用而非判断用
			fastNode = fastNode->next->next;
			slowNode = slowNode->next;

			if (fastNode == slowNode) {
				ListNode* idx1 = head;
				ListNode* idx2 = fastNode;
				while (idx1 != idx2) {
					idx1 = idx1->next;
					idx2 = idx2->next;
				}
				return idx1;
			}
		}
		return nullptr;
	}
};
int main() { return 0; }