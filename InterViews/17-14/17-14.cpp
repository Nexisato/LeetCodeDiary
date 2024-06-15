/*
@Description:
Design an algorithm to find the smallest K numbers in an array.

Note:
0 <= len(arr) <= 100000
0 <= k <= min(100000, len(arr))
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
思路：
最大堆
*/
class Solution {
public:
	vector<int> smallestK(vector<int>& arr, int k) {
		if (k == 0 || arr.size() == 0)
			return {};
		priority_queue<int, vector<int>, less<int>> maxHeap;
		for (auto& num : arr) {
			if (maxHeap.size() < k) {
				maxHeap.push(num);
				continue;
			}
			if (num < maxHeap.top()) {
				maxHeap.pop();
				maxHeap.push(num);
			}
		}
		vector<int> res;
		while (!maxHeap.empty()) {
			res.emplace_back(maxHeap.top());
			maxHeap.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
int main() { return 0; }