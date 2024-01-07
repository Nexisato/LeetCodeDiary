/*
 * @Date: 2024-01-07 14:42:55
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0138_Copy_List_with_Random_Pointer/138.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// 用哈希表记录一下对应的映射记录就行
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node *cur = head;
        Node *brandCur = new Node(cur->val);
        Node *brandHead = brandCur;
        unordered_map<Node*, Node*> table;
        table[cur] = brandCur;
        while (cur->next) {
            cur = cur->next;
            brandCur->next = new Node(cur->val);
            brandCur = brandCur->next;
            table[cur] = brandCur;
        }
        cur = head;
        while (cur) {
            if (cur->random) {
                table[cur]->random = table[cur->random];
            }
            cur = cur->next;
        }

        return brandHead;
    }
};
int main() {


    return 0;
}