/*
LeetCode 1035:
@Desciption:
We write the integers of nums1 and nums2 (in the order they are given) on two separate
horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers nums1[i] and
nums2[j] such that:

nums1[i] == nums2[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can
only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.

Note:
1 <= nums1.length <= 500
1 <= nums2.length <= 500
1 <= nums1[i], nums2[i] <= 2000
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：TODO:
*/
class Solution {
public:
	int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
		auto m = size(nums1), n = size(nums2);
		auto dp = vector(m + 1, vector(n + 1, 0));
		for (auto i = 0ull; i != m; ++i)
			for (auto j = 0ull; j != n; ++j)
				dp[i + 1][j + 1] =
				    max({dp[i + 1][j], dp[i][j + 1], dp[i][j] + (nums1[i] == nums2[j])});
		return dp.back().back();
	}
};
int main() { return 0; }