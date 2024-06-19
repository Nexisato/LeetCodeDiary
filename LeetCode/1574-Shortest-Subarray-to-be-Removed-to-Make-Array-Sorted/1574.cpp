#include <bits/stdc++.h>
using namespace std;
/**
 * @brief
 * 双指针
 * 从右往左遍历，找到右侧的单调递增数组
 * 从左边开始，保证每一个 arr[l]，都有 arr[r] >=
 * arr[l]，中间的数就是我们当前要删除的部分
 *
 */

class Solution {
public:
	int findLengthOfShortestSubarray(vector<int>& arr) {
		int n = arr.size();
		int left = 0, right = n - 1;
		while (right > 0 && arr[right - 1] <= arr[right])
			--right;
		if (right == 0)
			return 0;
		int res = right;
		for (; left < n; ++left) {
			while (right < n && arr[right] < arr[left])
				++right;
			res = min(res, right - left - 1);
			if (left + 1 < n && arr[left] > arr[left + 1])
				break;
		}
		return res;
	}
};

int main() { return 0; }