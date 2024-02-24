/*
 * @Date: 2024-02-24 14:54:07
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0000-Basic-Framework/heap.cpp
 * @Description: 
 */
 
#include <iostream>
using namespace std;
// 最大堆的上滤和下滤
class MaxHeap {
private:
    int* mHeap;
    int mCapacity;
    int mSize;
public:
    MaxHeap(int cap = 512): mCapacity(cap), mSize(0) {
        mHeap = new int[cap];
    }
    ~MaxHeap() {
        delete[] mHeap;
    }
    int size() {
        return mSize;
    }
    void filterUp(int start) {
        int cur = start;
        int parent = (cur - 1) / 2;
        while (cur > 0) {
            if (mHeap[cur] <= mHeap[parent]) break;
            swap(mHeap[cur], mHeap[parent]);
            cur = parent;
            parent = (cur - 1) / 2;
        }
    }
    void filterDown(int start, int end) {
        int cur = start;
        int l = 2 * cur + 1;
        int r = 2 * cur + 2;
        while (l <= end) {
            int maxIdx = (r <= end && mHeap[r] > mHeap[l]) ? r : l;
            if (mHeap[cur] >= mHeap[maxIdx]) break;
            swap(cur, maxIdx);
            cur = maxIdx;
            l = 2 * cur + 1;
            r = 2 * cur + 2;
        }
    }
    void insert(int data) {
        if (mSize == mCapacity) return;
        mHeap[mSize] = data;
        filterUp(mSize);
        ++mSize;
    }
    int pop() {
        if (mSize == 0) return -1;
        int res = mHeap[0];
        --mSize;
        mHeap[0] = mHeap[mSize];
        filterDown(0, mSize -  1);
        return res;
    }
    int top() {
        return mHeap[0];
    }
    bool empty() {
        return mSize == 0;
    }
};
// 最小堆的上滤和下滤
class MinHeap {
private:
    int* mHeap;
    int mCapacity;
    int mSize;
public:
    MinHeap(int cap = 512): mCapacity(cap), mSize(0) {
        mHeap = new int[cap];
    }
    ~MinHeap() {
        delete[] mHeap;
    }
    bool empty() {
        return mSize == 0;
    }
    void filterUp(int start) {
        int cur = start;
        int parent = (cur - 1) / 2;
        while (cur > 0) {
            if (mHeap[cur] >= mHeap[parent]) break;
            swap(mHeap[cur], mHeap[parent]);
            cur = parent;
            parent = (cur - 1) / 2;
        }
    }
    void filterDown(int start, int end) {
        int cur = start;
        int l = 2 * cur + 1;
        int r = 2 * cur + 2;
        while (l <= end) {
            int minIdx = (r <= end && mHeap[r] < mHeap[l]) ? r : l;
            if (mHeap[cur] <= mHeap[minIdx]) break;
            swap(cur, minIdx);
            cur = minIdx;
            l = 2 * cur + 1;
            r = 2 * cur + 2;
        }
    }
    void insert(int data) {
        if (mSize == mCapacity) return;
        mHeap[mSize] = data;
        filterUp(mSize);
        ++mSize;
    }
    int pop() {
        if (mSize == 0) return -1;
        int res = mHeap[0];
        --mSize;
        mHeap[0] = mHeap[mSize];
        filterDown(0, mSize - 1);
        return res;
    }
    int size() {
        return mSize;
    }
};
int main() {
    // MaxHeap *maxHeap = new MaxHeap();
    // maxHeap->insert(1);
    // maxHeap->insert(2);
    // maxHeap->insert(3);
    // cout << maxHeap->top() << endl;
    // cout << maxHeap->pop() << endl;
    // cout << maxHeap->top() << endl;
    // cout << maxHeap->pop() << endl;
    // cout << maxHeap->top() << endl;
    // cout << maxHeap->pop() << endl;
    MinHeap *minHeap = new MinHeap();
    minHeap->insert(3);
    minHeap->insert(2);
    minHeap->insert(1);
    while (!minHeap->empty()) {
        cout << minHeap->pop() << endl;
    }
    return 0;
}