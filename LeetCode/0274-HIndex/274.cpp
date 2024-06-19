/*
 * @Date: 2024-01-07 14:31:27
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0274_HIndex/274.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 二分查找 h-index
// 1. 首先对数组进行排序
// 2. 二分查找
// 3. 如果当前的值大于等于 n - mid，那么 h = n - mid，即不少于 n - mid 个值大于等于 n -
// mid
class Solution {
public:
	int hIndex(vector<int>& citations) {
		int h = 0;
		const int n = citations.size();
		sort(citations.begin(), citations.end());
		int l = 0, r = n - 1;
		while (l <= r) {
			int mid = l + ((r - l) >> 1);
			if (citations[mid] >= n - mid) {
				h = n - mid;
				r = mid - 1;
			} else
				l = mid + 1;
		}

		return h;
	}
};
int main() { return 0; }