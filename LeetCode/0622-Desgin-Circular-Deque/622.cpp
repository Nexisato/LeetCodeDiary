/*
LeetCode 622: Desgin Circular Deque
@Description:
Design your implementation of the circular queue. The circular queue is a linear data
structure in which the operations are performed based on FIFO (First In First Out)
principle and the last position is connected back to the first position to make a
circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front
of the queue. In a normal queue, once the queue becomes full, we cannot insert the next
element even if there is a space in front of the queue. But using the circular queue, we
can use the space to store new values.

Implementation the MyCircularQueue class:
- MyCircularQueue(k) Initializes the object with the size of the queue to be k.
- int Front() Gets the front item from the queue. If the queue is empty, return -1.
- int Rear() Gets the last item from the queue. If the queue is empty, return -1.
- boolean enQueue(int value) Inserts an element into the circular queue. Return true if
the operation is successful.
- boolean deQueue() Deletes an element from the circular queue. Return true if the
operation is successful.
- boolean isEmpty() Checks whether the circular queue is empty or not.
- boolean isFull() Checks whether the circular queue is full or not.

Constraints:
1 <= k <= 1000
0 <= value <= 1000
At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty, and isFull.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：空元素，不空元素
*/

/*空元素设计方法*/
class MyCircularQueue {
private:
	vector<int> elems;
	int cap;
	int head, tail;

public:
	MyCircularQueue(int k) {
		this->elems.clear();
		this->elems.resize(k + 1); //空出一个元素
		cap = k;
		head = 0; // head指向队首前一个元素
		tail = 0; // tail指向队尾元素
	}

	bool enQueue(int value) {
		if (this->isFull())
			return false;
		tail = (tail + 1) % (cap + 1);
		this->elems[tail] = value;
		return true;
	}

	bool deQueue() {
		if (this->isEmpty())
			return false;
		head = (head + 1) % (cap + 1);
		return true;
	}

	int Front() {
		if (this->isEmpty())
			return -1;
		return this->elems[(head + 1) % (cap + 1)];
	}

	int Rear() {
		if (this->isEmpty())
			return -1;
		return this->elems[tail];
	}

	bool isEmpty() { return (head == tail); }

	bool isFull() { return ((tail + 1) % (cap + 1) == head); }
};

/*不空元素设计方法*/
class MyCircularQueue_ref {
private:
	vector<int> data;
	int head;
	int tail;
	int size;

public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		data.resize(k);
		head = -1;
		tail = -1;
		size = k;
	}

	/** Insert an element into the circular queue. Return true if the operation is
	 * successful. */
	bool enQueue(int value) {
		if (isFull()) {
			return false;
		}
		if (isEmpty()) {
			head = 0;
		}
		tail = (tail + 1) % size;
		data[tail] = value;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is
	 * successful. */
	bool deQueue() {
		if (isEmpty()) {
			return false;
		}
		if (head == tail) {
			head = -1;
			tail = -1;
			return true;
		}
		head = (head + 1) % size;
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if (isEmpty()) {
			return -1;
		}
		return data[head];
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (isEmpty()) {
			return -1;
		}
		return data[tail];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() { return head == -1; }

	/** Checks whether the circular queue is full or not. */
	bool isFull() { return ((tail + 1) % size) == head; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {
	MyCircularQueue* obj = new MyCircularQueue(3);
	bool param_1 = obj->enQueue(2);
	int param_2 = obj->Rear();
	int param_3 = obj->Front();
	bool param_4 = obj->deQueue();
	int param_5 = obj->Front();
	bool param_6 = obj->deQueue();
	int param_7 = obj->Front();
	bool param_8 = obj->isEmpty();
	bool param_9 = obj->isFull();
	bool param_10 = obj->enQueue(4);
	bool param_11 = obj->enQueue(2);
	bool param_12 = obj->enQueue(2);
	bool param_13 = obj->enQueue(3);

	return 0;
}