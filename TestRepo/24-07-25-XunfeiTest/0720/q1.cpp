#include <iostream>
#include <queue>
#include <vector>

// 对顶堆动态找中位数，由大顶堆或者小顶堆维护序列顺序
class MedianFinder {
private:
	std::priority_queue<int, std::vector<int>> maxHeap;
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

public:
	MedianFinder() {}
	void addNum(int num) {
		if (maxHeap.size() == minHeap.size()) {
			if (maxHeap.empty() || num <= maxHeap.top()) {
				maxHeap.push(num);
			} else {
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(num);
			}
		} else {
			if (num <= maxHeap.top()) {
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(num);
			} else {
				minHeap.push(num);
			}
		}
	}
	int popFindMedian() {
		int x = 0;
		if (maxHeap.size() == minHeap.size()) {
			if (maxHeap.top() <= minHeap.top()) {
				x = maxHeap.top();
				maxHeap.pop();
				maxHeap.push(minHeap.top());
				minHeap.pop();
			} else {
				x = minHeap.top();
				minHeap.pop();
			}
		} else {
			x = maxHeap.top();
			maxHeap.pop();
		}
		return x;
	}
};
int main() {
	int n;
	std::cin >> n;
	MedianFinder mf;
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		mf.addNum(x);
	}
	for (int i = 0; i < n; ++i) {
		std::cout << mf.popFindMedian() << " ";
	}
	std::cout << std::endl;
	return 0;
}