/*
 * @Date: 2024-01-19 12:31:04
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0086-Partition-List/86.cpp
 * @Description:
 */
#include <iostream>
#include <string>
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
	// 记录两个指针
	ListNode* partition(ListNode* head, int x) {
		if (!head || !head->next)
			return head;
		ListNode* samllNode = new ListNode(-101);
		ListNode* bigNode = new ListNode(-101);
		ListNode* node = head;
		ListNode *samllHead = samllNode, *bigHead = bigNode;
		while (node) {
			if (node->val < x) {
				samllNode->next = node;
				samllNode = samllNode->next;
			} else {
				bigNode->next = node;
				bigNode = bigNode->next;
			}
			node = node->next;
		}
		bigNode->next = nullptr;
		samllNode->next = bigHead->next;
		return samllHead->next;
	}
};
int main() { return 0; }