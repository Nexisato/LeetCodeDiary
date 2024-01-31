/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0024-Swap-node-in-pairs/24-Swap-node-in-pairs.cpp
 * @Description: 
 */
/*
Description:
Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes. Only nodes itself may be changed.

Constraints:
The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
// class Solution {
//     /*
//     思路：
//     1. 递归： 确定参数和返回值；确定终止条件；确定单层递归逻辑
//     2. 若链表前两个节点中任一项为空，返回
//     3. 交换链表的前两个节点，即 head 和 head->next
//     4. 调用函数自身，入口参数设置为第三个节点，即 head->next->next
//     */
// private:
//     void swap(ListNode* head) {
//         if (!head || !head->next) return;
//         int temp = head->val;
//         ListNode* postnode = head->next;
//         head->val = postnode->val;
//         postnode->val = temp;
//         swap(postnode->next);
//     }
// public:
//     ListNode* swapPairs(ListNode* head) {
//         swap(head);
//         return head;
//     }
//     void Print(ListNode* head){
//         ListNode *p=head;
//         while(p){
//             cout<<p->val<<" ";
//             p=p->next;
//         }
//     }
// };
/*
思路：有点绕，画图辅助
1. 设置virtual node辅助，postnode囊括一对
2. 记录 + 反转 + 移动
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *virnode = new ListNode(-1);
        virnode->next = head;
        ListNode *curnode = virnode, *postnode = head;

        while (postnode!= nullptr && postnode->next != nullptr) {
            ListNode *tmp = postnode->next->next; //记录下一对起点
            
            curnode->next = postnode->next;   //curnode标记 反转后的node对起点
            postnode->next->next = postnode;  //反转
            postnode->next = tmp;             // node对终点指向下一对起点
            
            curnode = postnode;               //移动
            postnode = tmp;
        }
        ListNode *node = virnode->next;
        delete virnode;
        return node;

    }
    ListNode* swapPairs_group(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *virNode = new ListNode(-1, head);
        ListNode *cur = head, *post = nullptr;
        ListNode *prev = virNode;
        ListNode *tail = cur, *concat = prev;
        while (tail && tail->next) {
            for (int i = 0; i < 2; ++i) {
                post = cur->next;
                cur->next = prev;
                prev = cur;
                cur = post;
            }
            tail->next = cur;
            concat->next = prev;
            concat = tail;
            tail = cur;
        }
        return virNode->next;

    }
};

int main(){
    ListNode *head=new ListNode(0);
    ListNode *p=head;
    for(int i=0;i<5;i++){
        ListNode *node=new ListNode(i+1);
        p->next=node;
        p=node;
    }
    p->next=nullptr;
    Solution ss;
    // ss.Print(head);
    // cout<<"\n-----------"<<endl;
    // p=ss.swapPairs(head);
    // ss.Print(p);
    return 0;
}