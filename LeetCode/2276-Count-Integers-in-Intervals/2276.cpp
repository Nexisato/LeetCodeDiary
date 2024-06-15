#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 思路：统计区间
 *
 */
class CountIntervals {
private:
	int l, r, cnt = 0;
	CountIntervals *leftNode = nullptr, *rightNode = nullptr;
	// 动态开点的线段树

public:
	CountIntervals() : l(0), r(1e+9) {}
	CountIntervals(int left, int right) : l(left), r(right) {}

	void add(int left, int right) {
		// 区间已经被完全覆盖
		if (cnt == r - l + 1)
			return;
		// 因为这个线段树只能管这么大的区间，所以如果区间超出了范围，就返回最大的区间大小
		if (left <= l && r <= right) {
			cnt = r - l + 1;
			return;
		}
		// 二分的话注意下面的运算符优先级
		int mid = l + ((r - l) >> 1);
		if (!leftNode)
			leftNode = new CountIntervals(l, mid);
		if (!rightNode)
			rightNode = new CountIntervals(mid + 1, r);
		if (left <= mid)
			leftNode->add(left, right);
		if (right > mid)
			rightNode->add(left, right);
		cnt = leftNode->cnt + rightNode->cnt;
	}

	int count() { return cnt; }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */

int main() { return 0; }