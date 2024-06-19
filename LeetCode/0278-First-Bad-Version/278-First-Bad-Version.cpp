/*
LeetCode: 278 First Bad Version
Description:
You are a product manager and currently leading a team to develop a new product.
Unfortunately, the latest version of your product fails the quality check.
Since each version is developed based on the previous version, all the versions after a
bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one,
which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad.
Implement a function to find the first bad version. You should minimize the number of
calls to the API.

Constraints:
1 <= bad <= n <= 2^31 - 1
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
二分查找的边界问题
1. 若 isBadVersion == true, 则搜索空间为 mid 及 mid左侧 [left, mid]
2. 若 isBadVersion == false，则搜索空间为 mid（不包括mid） 右侧 [mid+1, right]
*/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
class Solution {
public:
	bool isBadVersion(int version) {
		int bad = 2;
		return (version == bad) ? true : false;
	}
	int firstBadVersion(int n) {
		int l = 1, r = n;
		int mid = 1;
		while (l < r) {
			mid = l + (r - l) / 2;
			if (isBadVersion(mid)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		return l;
	}
};
int main() {
	Solution ss;
	int n = 3;
	cout << ss.firstBadVersion(n) << endl;
	return 0;
}