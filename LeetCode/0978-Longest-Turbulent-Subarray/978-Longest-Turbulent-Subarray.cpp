/*
LeetCode 978: Longest Turbulent Subarray
@Description:
Given an integer array arr, return the length of a maximum size turbulent subarray of
arr.

A subarray is turbulent if the comparison sign flips between each adjacent pair of
elements in the subarray.

More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be
turbulent if and only if:

For i <= k < j:
arr[k] > arr[k + 1] when k is odd, and
arr[k] < arr[k + 1] when k is even.
Or, for i <= k < j:
arr[k] > arr[k + 1] when k is even, and
arr[k] < arr[k + 1] when k is odd.

Constraints:
1 <= arr.length <= 4 * 10^4
0 <= arr[i] <= 10^9
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：滑动窗口

*/
class Solution {
public:
	int maxTurbulenceSize(vector<int>& arr) {
		int left = 0, right = 0;
		int maxL = 1;
		while (right < arr.size() - 1) {
			if (left == right) {
				if (arr[left] == arr[left + 1])
					left++;
				right++;
			} else {
				if (arr[right - 1] < arr[right] && arr[right] > arr[right + 1])
					right++;
				else if (arr[right - 1] > arr[right] && arr[right] < arr[right + 1])
					right++;
				else
					left = right;
			}
			maxL = (maxL > right - left + 1) ? maxL : right - left + 1;
		}
		return maxL;
	}
};
int main() { return 0; }