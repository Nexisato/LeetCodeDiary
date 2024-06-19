/*
LeetCode 703: Kth Largest Element in a Stream
@Description:
Design a class to find the kth largest element in a stream.
Note that it is the kth largest element in the sorted order, not the kth distinct
element.

Implement KthLargest class:
KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream
of integers nums. int add(int val) Returns the element representing the kth largest
element in the stream.

Constraints:
1 <= k <= 10^4
0 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
-10^4 <= val <= 10^4
At most 10^4 calls will be made to add.
It is guaranteed that there will be at least k elements in the array when you search for
the kth element.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：TopK，使用小顶堆
1. 使用一个大小为k的小顶堆存储前k大的元素，则堆顶即为topK
2. 在单次插入操作中，将元素val插入到优先队列中
    若此时优先队列大小大于k，则需要将优先队列队头弹出，以保证优先队列大小为k
*/
class KthLargest {
	int k;
	priority_queue<int, vector<int>, greater<int>> minHeap;

public:
	KthLargest(int k, vector<int>& nums) {
		this->k = k;
		for (auto& num : nums)
			add(num);
	}
	int add(int val) {
		minHeap.push(val);
		while (minHeap.size() > k)
			minHeap.pop();
		return minHeap.top();
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
int main() {
	int k = 0;
	vector<int> nums = {};
	KthLargest ss(k, nums);

	return 0;
}