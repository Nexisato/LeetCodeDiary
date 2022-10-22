#include <bits/stdc++.h>
using namespace std;

struct DListNode {
    int val;
    DListNode *prev, *next;
    DListNode(int _val): val(_val), prev(nullptr), next(nullptr) {}

};

class MyLinkedList {
private:
    int size;
    DListNode *head, *tail;
public:
    MyLinkedList() {
        this->size = 0;
        this->head = new DListNode(-1);
        this->tail = new DListNode(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int index) {
        if (index < 0 || index >= size)
            return -1;
        DListNode *node;
        if (index + 1 < size - index) {
            node = head;
            for (int i = 0; i <= index; ++i)
                node = node->next;
        } else {
            node = tail;
            for (int i = 0; i < size-index; ++i)
                node = node->prev;
        }
        return node->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > size)
            return;
        index = max(0, index);
        DListNode *pred, *succ;
        if (index < size - index) {
            pred = head;
            for (int i = 0; i < index; ++i)
                pred = pred->next;
            succ = pred->next;
        } else {
            succ = tail;
            for (int i = 0; i < size-index; ++i)
                succ = succ->prev;
            pred = succ->prev;
        }
        ++size;
        DListNode *node = new DListNode(val);
        node->prev = pred;
        node->next = succ;
        pred->next = node;
        succ->prev = node;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size || index < 0)
            return;
        DListNode *pred, *succ;
        if (index < size - index) {
            pred = head;
            for (int i = 0; i < index; ++i)
                pred = pred->next;
            succ = pred->next->next;
        } else {
            succ = tail;
            for (int i = 0; i < size-index-1; ++i)
                succ = succ->prev;
            pred = succ->prev->prev;
        }
        --size;
        DListNode *p = pred->next;
        pred->next = succ;
        succ->prev = pred;
        delete p;

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main() {
    MyLinkedList *root = new MyLinkedList();
    root->addAtHead(1);
    root->addAtTail(3);
    root->addAtIndex(1, 2);
    cout << root->get(1) << endl;
    root->deleteAtIndex(1);
    cout << root->get(1) << endl;;

    return 0;
}


