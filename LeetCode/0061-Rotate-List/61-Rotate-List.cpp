/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0061-Rotate-List/61-Rotate-List.cpp
 * @Description: 
 */
/*
LeetCode 61: Rotate List
@Description:
Given the head of a linked list, rotate the list to the right by k places.

Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 10^9
*/
#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
思路：
1. 先遍历一遍单链表记录长度 length
2. 取 k = length - (k % length)，求出从头节点开始需要移动的位数
3. prenode用于记录，node用于遍历，移动位数到达k，prenode指空，node则为旋转链表的头节点
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next)
            return head;
        int length = 1;
        ListNode *node = head, *prenode = nullptr;
        while (node->next) {
            node = node->next;
            length++;
        }
        node->next = head;
        k = length - (k % length);
        node = head;
        while (k--) {
            prenode = node;
            node = node->next;
        }
        ListNode *res = node;
        prenode->next = nullptr;
        return res;
    }
};
int main() {


    return 0;
}