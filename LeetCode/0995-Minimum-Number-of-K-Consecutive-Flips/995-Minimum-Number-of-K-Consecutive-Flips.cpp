/*
LeetCode 995: Minimum Number of K Consecutive Flips
@Description:
In an array A containing only 0s and 1s, a K-bit flip consists of choosing a
(contiguous) subarray of length K and simultaneously changing every 0 in the subarray to
1, and every 1 in the subarray to 0.

Return the minimum number of K-bit flips required so that there is no 0 in the array. 
If it is not possible, return -1.

Note:
1 <= A.length <= 30000
1 <= K <= A.length
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：差分数组
1. 对于若干个K位翻转操作，改变先后顺序并不影响最终结果。因此从头遍历，只翻转 A[i] ==
0的子数组
2. 翻转操作是唯一的
3.
采用差分数组，不翻转数字，统计每个数字需要翻转的次数。一次翻转相当于将子数组中所有数字的翻转次数+1
4. 遍历到A[i]时，若A[i]+revCnt为偶数，则当前位为0，需要翻转[i, i + K - 1]
*/
class Solution {
public:
	int minKBitFlips(vector<int>& A, int K) {
		vector<int> diff(A.size() + 1);
		int res = 0, revCnt = 0;
		for (int i = 0; i < A.size(); ++i) {
			revCnt ^= diff[i];
			if (A[i] == revCnt) {
				if (i + K > A.size())
					return -1;
				++res;
				revCnt ^= 1;
				diff[i + K] ^= 1;
			}
		}
		return res;
	}
};
/*
思路：滑动窗口
*/
class Solution_windows {
public:
	int minKBitFlips(vector<int>& A, int K) {
		int res = 0, revCnt = 0;
		for (int i = 0; i < A.size(); ++i) {
			if (i >= K && A[i - K] > 1) {
				revCnt ^= 1;
				A[i - K] -= 2;
			}
			if (A[i] == revCnt) {
				if (i + K > A.size())
					return -1;
				++res;
				revCnt ^= 1;
				A[i] += 2;
			}
		}
		return res;
	}
};
int main() { return 0; }