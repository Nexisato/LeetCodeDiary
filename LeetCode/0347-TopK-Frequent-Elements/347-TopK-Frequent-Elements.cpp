/*
LeetCode 347: Top K Frequent Frequent Elements
@Description:
Given an integer array nums and an integer k, return the k most frequent elements.
You may return the answer in any order.

Constraints:
1 <= nums.length <= 10^5
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：最小堆，但元素按pair存储
*/
class Solution {
private:
	static bool cmp(pair<int, int>& a, pair<int, int>& b) { return a.second > b.second; }

public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> table;
		for (auto& num : nums)
			table[num]++;
		// decltype()：类型自动推导
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> minHeap(cmp);
		for (auto it = table.begin(); it != table.end(); ++it) {
			if (minHeap.size() < k) {
				minHeap.push({it->first, it->second});
				continue;
			}
			if (it->second > minHeap.top().second) {
				minHeap.pop();
				minHeap.push({it->first, it->second});
			}
		}
		vector<int> res;
		while (!minHeap.empty()) {
			res.emplace_back(minHeap.top().first);
			minHeap.pop();
		}
		return res;
	}
};
int main() { return 0; }