/*
LeetCode 1442: Count Triplets That Can Form Two Arrays of Equal XOR
@Description:
Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:
- a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
- b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.

Constraints:
1 <= arr.length <= 300
1 <= arr[i] <= 10^8
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：利用[前缀异或] & [哈希表]
1. 依靠前缀异或的思路，我们可以得到O(n^3)的解决方案
2. 辅助哈希表进行查询
    题目等价于让我们从一段连续的区间[i, k]中，找到一个分割点j，使得左右两侧的异或结果相等
    即：sum[k] ^ sum[i - 1] = 0，即sum[k] == sum[i - 1]
*/
class Solution {
public:
	int countTriplets(vector<int>& arr) {
		int n = arr.size();
		vector<int> xorSum(n + 1, 0);
		for (int i = 1; i <= n; ++i)
			xorSum[i] = xorSum[i - 1] ^ arr[i - 1];

		int res = 0;
		for (int i = 0; i < n; ++i)
			for (int k = i + 1; k <= n; ++k)
				if (xorSum[k] == xorSum[i])
					res += k - i - 1;
		return res;
	}
};
int main() { return 0; }