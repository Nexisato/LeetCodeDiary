/*
 * @Date: 2024-02-12 08:06:49
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0023-Merge-K-Sorted-Lists/23.cpp
 * @Description:
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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		vector<int> nums;
		for (auto& list : lists) {
			while (list) {
				nums.push_back(list->val);
				list = list->next;
			}
		}
		sort(nums.begin(), nums.end());
		for (auto& num : nums) {
			cur->next = new ListNode(num);
			cur = cur->next;
		}
		return dummy->next;
	}
};
int main() { return 0; }