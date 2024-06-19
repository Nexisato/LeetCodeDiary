/*
 * @Date: 2023-12-10 01:13:32
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0918-Maximum-Circular-Subarray/918.cpp
 * @Description:
 */
/*
LeetCode 918: Maximum Circular Subarray
@Description:
Given a circular array C of integers represented by A, find the maximum possible sum
of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the
array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i
>= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once. 
(Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j
with k1 % A.length = k2 % A.length.)

Note:
-30000 <= A[i] <= 30000
1 <= A.length <= 30000
*/
#include <iostream>
#include <vector>
using namespace std;
/*
【思路】：Kadane算法
dp[j]为以nums[j]结尾的最大子序和，则dp[j + 1] = max(dp[j] + A[j], A[j])
简化空间复杂度:
res = 0, cur = 0;
for num : nums
    cur = x + max(cur, 0)
    res = max(res, cur)
return res
以上为计算单区间子段的最大值算法，对于双区间字段，考虑
T_j = A[j] + A[j + 1] + A[j + 2] + ... A[A.length() - 1]
R_j = max T_k (k>=j)
所以需要计算A[0] + A[1] + .. + A[i] + R_(i + 2)
*/
class Solution {
public:
	int maxSubarraySumCircular(vector<int>& A) {
		int n = A.size();
		// res为单区间子段的最大子序和，即 Maximum Suarray
		int res = A[0], cur = A[0];
		for (int i = 1; i < n; ++i) {
			cur = A[i] + max(cur, 0);
			res = max(res, cur);
		}

		// rightSum：计算倒序连续子序和rightSum[j] = A[n - 1] + A[n - 2]
		// +....+A[j]，对应T_j
		vector<int> rightSum(A);
		for (int j = n - 2; j >= 0; --j)
			rightSum[j] = A[j] + rightSum[j + 1];
		// maxRight：maxRight[i]为满足j >= i 的最大rightSum[j]，对应R_j
		vector<int> maxRight(A);
		for (int j = n - 2; j >= 0; --j)
			maxRight[j] = max(maxRight[j + 1], rightSum[j]);
		// leftSum：计算正序连续子序和
		int leftSum = 0;
		for (int i = 0; i < n - 2; ++i) {
			leftSum += A[i];
			res = max(res, leftSum + maxRight[i + 2]);
		}
		return res;
	}
};
int main() { return 0; }