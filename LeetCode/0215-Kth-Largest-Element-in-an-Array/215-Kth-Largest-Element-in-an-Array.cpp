/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath:
 * /LeetCodeDiary/LeetCode/0215-Kth-Largest-Element-in-an-Array/215-Kth-Largest-Element-in-an-Array.cpp
 * @Description:
 */
/*
Description:
Find the kth largest element in an unsorted array.
Note that it is the kth largest element in the sorted order, not the kth distinct
element.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
思路:
    1. (调库侠)：降序快排，直接返回第k个索引 TC:O(nlogn) ，最好不要这么写
    2. 堆排序
*/
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		return sort(nums.begin(), nums.end(), greater<int>()), nums[k - 1];
	}
};
/*
思路：创建一个容量为K的最小堆，遇到数组中有大于堆顶的元素，则出堆入堆一次
*/
class Solution_heap {
public:
	int findKthLargest(vector<int>& nums, int k) {
		if (k == 0)
			return {};
		priority_queue<int, vector<int>, greater<int>> minHeap;
		int n = nums.size();
		int heap_size = 0;
		for (int i = 0; i < n; ++i) {
			if (heap_size < k) {
				minHeap.push(nums[i]);
				heap_size++;
			} else {
				if (nums[i] > minHeap.top()) {
					minHeap.pop();
					minHeap.push(nums[i]);
				}
			}
		}
		return minHeap.top();
	}
};
int main() { return 0; }