/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0082_Remove_Duplicates_from_Sorted_List_II/82_Remove_Duplicate_from_Sorted_List_II.cpp
 * @Description: 
 */
/*
LeetCode 82: Remove Duplicate Elements from Sorted List II
@Description:
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. Return the linked list sorted as well.

Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
思路：用数组记录出现次数，然后将出现次数为1的节点连接起来
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *node = head, *ptr = nullptr, *firstNode = nullptr;
        vector<int> count(201, 0);
        int index = 0;
        while (node != nullptr) {
            index = node->val + 100;
            count[index]++;
            node = node->next;
        }
        node = head;
        bool firstFlag = true;
        while (node != nullptr) {
            if (count[node->val + 100] == 1) {
                if (firstFlag) { 
                    ptr = new ListNode(node->val);
                    firstNode = ptr;
                    firstFlag = false;
                }
                else {
                    ptr->next = node;
                    ptr = node;
                }
            }
            node = node->next;
        }
        if (ptr != nullptr)
            ptr->next = nullptr;
        return firstNode;
    }
};

/*
思路：
由于链表是排好序的，因此重复的元素在链表中是连续出现的，因此只需要遍历一次，即可删除重复节点
*/
class Solution_space_less {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        //虚节点，常用的处理方式
        ListNode *virNode = new ListNode(0, head);
        ListNode *node = virNode;
        int num = virNode->val;
        while (node->next && node->next->next) {
            //检查重复节点
            if (node->next->val == node->next->next->val) {
                num = node->next->val;
                while (node->next && node->next->val == num)
                    node->next = node->next->next; 
            }
            else
                node = node->next;
        }
        return virNode->next;
    }

};
int main() {


    return 0;
}