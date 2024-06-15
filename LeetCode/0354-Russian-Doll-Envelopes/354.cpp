/*
LeetCode 354: Russian Doll Envelopes
@Description:
You have a number of envelopes with widths and heights given as a pair of integers (w, h).
One envelope can fit into another if and only if both the width and height of one envelope
is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：经典动态规划问题 LIS(最长上升子序列)
1. 定义dp[i]为前i个信封中，以信封 i （已选取）结尾的最大套娃数
2. 对于每个dp[i]而言，最小值为1，即只选择一个信封；前i - 1中只要一个符合条件的即可
    - 即 max(dp[i], dp[j] + 1)
*/

class Solution {
public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		int n = envelopes.size();
		sort(envelopes.begin(), envelopes.end(), [](const vector<int>& nums1, const vector<int>& nums2) {
			return nums1[0] < nums2[0] || (nums1[0] == nums2[0]) && (nums1[1] < nums2[1]);
		});
		int res = 1;
		vector<int> dp(n, 1);
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j)
				if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
					dp[i] = max(dp[i], dp[j] + 1);
			res = max(res, dp[i]);
		}
		return res;
	}
};
int main() {
	vector<vector<int>> envelopes = {{3, 2}, {3, 1}, {5, 3}};
	sort(envelopes.begin(), envelopes.end(), [](const vector<int>& nums1, const vector<int>& nums2) {
		return (nums1[0] < nums2[0]) || (nums1[0] == nums2[0] && nums1[1] < nums2[1]);
	});
	for (int i = 0; i < 3; ++i)
		cout << envelopes[i][0] << " " << envelopes[i][1] << endl;

	return 0;
}
