/*
LCOffer 6: Print Reverse List
@Description:
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
*/
#include <bits/stdc++.h>
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
	vector<int> reversePrint(ListNode* head) {
		ListNode* node = head;
		if (node == nullptr)
			return {};
		vector<int> res;
		while (node != nullptr) {
			res.emplace_back(node->val);
			node = node->next;
		}
		int l = 0, r = res.size() - 1;
		while (l < r)
			swap(res[l++], res[r--]);
		return res;
	}
};
int main() { return 0; }