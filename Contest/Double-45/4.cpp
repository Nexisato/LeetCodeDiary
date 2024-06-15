/*
LeetCode 1751:  Maximum Number of Events That Can Be Attended II;
@Description:
You are given an array of events where events[i] = [startDayi, endDayi, valuei].
The ith event starts at startDayi and ends at endDayi, and if you attend this event,
you will receive a value of valuei. You are also given an integer k which represents
the maximum number of events you can attend.

You can only attend one event at a time. If you choose to attend an event,
you must attend the entire event. Note that the end day is inclusive:
that is, you cannot attend two events where one of them starts and the other ends on the same day.

Return the maximum sum of values that you can receive by attending events.

Constraints:
1 <= k <= events.length
1 <= k * events.length <= 10^6
1 <= startDayi <= endDayi <= 10^9
1 <= valuei <= 10^6
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：动态规划 + 二分搜索
1. 首先将每个会议按照结束时间排序
2. 假设dp[i][k]为参加前i个会议中恰好k个时，所能获得的最大价值
3. 对于dp[i][k]而言，有如下两种情况：
    · 不参加第i个会议，此时需要在前i-1个会议中参加k个，能够获得价值dp[i - 1][k]
    · 参加第i个会议，此时对于任何会议j，若满足startDayj >= endDayi，则都会因时间冲突无法参加
        · 设 l 为满足 l < i 且 endDayl < startDayi的最后一个会议，则dp[i][k] = dp[l][k - 1] + value[i](二分)
        · 若 l 不存在时，即参加第i个会议则此前所有会议都无法参加
*/
class Solution {
private:
	static bool cmp(const vector<int>& x, const vector<int>& y) { return x[1] < y[1]; }

public:
	int maxValue(vector<vector<int>>& events, int k) {
		int N = events.size();
		sort(events.begin(), events.end(), cmp);
		vector<vector<int>> dp(N, vector<int>(k + 1, INT32_MIN));
		dp[0][0] = 0;
		dp[0][1] = events[0][2];

		for (int i = 1; i < N; ++i) {
			//参加会议i，
			int left = 0, right = i;
			while (right - left > 1) {
				int mid = (left + right) / 2;
				if (events[mid][1] >= events[i][0])
					right = mid;
				else
					left = mid;
			}
			if (events[left][1] < events[i][0])
				for (int j = 1; j <= k; ++j)
					dp[i][j] = max(dp[i][j], dp[left][j - 1] + events[i][2]);
			else
				dp[i][1] = max(dp[i][1], events[i][2]);
		}
	}
};
int main() { return 0; }