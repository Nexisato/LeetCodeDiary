/*
 * @Date: 2024-02-02 11:40:33
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0295-Find-Median-of-Data-Stream/295.cpp
 * @Description:
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
private:
	// 大顶堆，记录左半边元素
	priority_queue<int, vector<int>, less<int>> lHeap;
	// 小顶堆，记录右半边元素
	priority_queue<int, vector<int>, greater<int>> rHeap;

public:
	MedianFinder() {
		lHeap = priority_queue<int, vector<int>, less<int>>();
		rHeap = priority_queue<int, vector<int>, greater<int>>();
	}
	// 入堆的时候需要保持平衡
	void addNum(int num) {
		// 堆大小相等，根据插入元素与右堆堆顶元素的大小关系，决定插入左堆还是右堆
		if (lHeap.size() == rHeap.size()) {
			if (rHeap.empty() || num <= rHeap.top()) {
				lHeap.push(num);
			} else {
				lHeap.push(rHeap.top());
				rHeap.pop();
				rHeap.push(num);
			}
		} else {
			if (num >= lHeap.top()) {
				rHeap.push(num);
			} else {
				rHeap.push(lHeap.top());
				lHeap.pop();
				lHeap.push(num);
			}
		}
	}

	double findMedian() {
		if (lHeap.size() == rHeap.size()) {
			return (lHeap.top() + rHeap.top()) / 2.0;
		} else {
			return lHeap.top();
		}
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() { return 0; }