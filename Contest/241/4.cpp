/*
LeetCode 1866: Number of Ways to Rearrange Sticks With K Sticks Visible
@Description:
There are n uniquely-sized sticks whose lengths are integers from 1 to n.
You want to arrange the sticks such that exactly k sticks are visible from the left.
A stick is visible from the left if there are no longer sticks to the left of it.

For example, if the sticks are arranged [1,3,2,5,4], then the sticks with lengths 1, 3,
and 5 are visible from the left. Given n and k, return the number of such arrangements.
Since the answer may be large, return it modulo 1e9 + 7.

Constraints:
1 <= n <= 1000
1 <= k <= n
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：标准dp
我们用dp[i][j]表示长度为1,2,...,i的木棍中可以被看到j根木棍的方案数
状态转移分析过程如下：
    - 若最后一根木棍可以被看到，则一定长为i，那么dp[i][j] = dp[i - 1][j - 1]
    - 若最后一根木棍不可被看到，则最后一根木棍长为[1..i -1]中的某个值，则
        dp[i][j] = dp[i - 1][j] * (i - 1)
    dp[i][j] = dp[i - 1][j - 1] + (i - 1) * dp[i - 1, j]
由于dp[i]只能从dp[i - 1]转换而来，因此可以用两个一维数组进行状态压缩
*/
class Solution {
private:
	static constexpr int mode = 1e9 + 7;

public:
	int rearrangeSticks(int n, int k) {
		vector<int> dp(k + 1);
		dp[0] = 1;
		for (int i = 1; i <= n; ++i) {
			vector<int> pre(k + 1);
			for (int j = 1; j <= k; ++j) {
				pre[j] = ((long long)dp[j] * (i - 1) % mode + dp[j - 1]) % mode;
			}
			dp = move(pre);
		}
		return dp[k];
	}
};
int main() { return 0; }