/*
Description:
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/
#include <iostream>
#include <functional>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
思路：双指针法
1. 定义 slowPtr 和 fastPtr，fastPtr每次移动两个节点， slowPtr每次移动一个节点
2. 定义 prePtr 记录 slowPtr 的前一个节点
3. fastPtr 到达终止位置时，slowPtr 位于链表的中间位置
4. prePtr 将链表分割为两个部分，后一部分的长度大于等于前一部分（长为奇数）
5. 反转后半部分的链表，并按照前半部分的链表长度进行比较
*/
class Solution_lambda {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slowPtr = head, *fastPtr = head;
        while (fastPtr && fastPtr->next) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        ListNode* middlePtr = slowPtr;
        function<ListNode*(ListNode*)> reverse = [](ListNode* node) -> ListNode* {
            if (!node) return nullptr;
            ListNode *pre = nullptr, *cur = node, *post = nullptr;
            while (cur) {
                post = cur->next;
                cur->next = pre;
                pre = cur;
                cur = post;
            }
            return pre;
        };
        ListNode *midHead = reverse(middlePtr);
        while (head && midHead) {
            if (head->val != midHead->val)
                return false;
            head = head->next;
            midHead = midHead->next;
        }
        return true;
    }
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)
			return true;
		ListNode *slowPtr = head, *fastPtr = head, *prePtr = head;
		while (fastPtr && fastPtr->next) {
			prePtr = slowPtr;
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next->next;
		}
		prePtr->next = nullptr;
		ListNode* cur1 = head;
		ListNode* cur2 = reverseList(slowPtr);
		while (cur1) {
			if (cur1->val != cur2->val)
				return false;
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return true;
	}
	ListNode* reverseList(ListNode* head) {
		// if (!head) return nullptr;
		ListNode *node = head, *prenode = nullptr, *postnode = head;
		while (node) {
			postnode = node->next;
			node->next = prenode;
			prenode = node;
			node = postnode;
		}
		return prenode;
	}
};

/*
思路：递归/后序遍历
核心逻辑：将链表节点入栈，再拿出来，此时元素顺序就是反的
容易超时
*/
class Solution_dong {
	ListNode* left;

public:
	bool isPalindrome(ListNode* head) {
		left = head;
		return traverse(head);
	}
	bool traverse(ListNode* right) {
		if (right == nullptr)
			return true;
		bool res = traverse(right->next);
		res = res && (right->val == left->val);
		left = left->next;
		return res;
	}
};

int main() { return 0; }