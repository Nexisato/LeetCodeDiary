#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * 不要用最大堆，每次 Pop 出的是最大值，
 * 自行构造一个队列，使得我们能够维护队列的最大值，并且每次出入队符合滑动窗口的顺序
 *
 */
class MyQueue {
private:
	deque<int> q;

public:
	void pop(int value) {
		if (!q.empty() && value == q.front())
			q.pop_front();
	}

	void push(int value) {
		while (!q.empty() && value > q.back())
			q.pop_back();
		q.push_back(value);
	}
	int front() { return q.front(); }
};
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		int n = nums.size();

		MyQueue q;
		for (int i = 0; i < k; ++i)
			q.push(nums[i]);

		res.push_back(q.front());
		for (int i = k; i < n; ++i) {
			q.pop(nums[i - k]); // pop掉队列前
			q.push(nums[i]);
			res.push_back(q.front());
		}
		return res;
	}
};
int main() { return 0; }