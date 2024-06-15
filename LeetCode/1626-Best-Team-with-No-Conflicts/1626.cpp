#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void qSort(vector<int>& scores, vector<int>& ages, int start, int end) {
		if (start >= end)
			return;
		int l = start, r = end;
		int pivot = scores[l];
		//反向
		while (l < r) {
			while (l < r && scores[r] <= pivot)
				--r;
			while (l < r && scores[l] >= pivot)
				++l;
			if (l < r) {
				swap(scores[l], scores[r]);
				swap(ages[l], ages[r]);
			}
		}
		swap(scores[l], scores[start]);
		swap(ages[l], ages[start]);
		qSort(scores, ages, start, l - 1);
		qSort(scores, ages, l + 1, end);
	}

public:
	/**
	 * @brief
	 * 由于按照分数升序排序，保证后一名球员的分数一定不小于前一名球员的分数
	 * @param scores
	 * @param ages
	 * @return int
	 */
	int bestTeamScore(vector<int>& scores, vector<int>& ages) {
		int n = scores.size();
		int res = 0;
		vector<vector<int>> player(n, vector<int>(2, 0));
		for (int i = 0; i < n; i++) {
			player[i][0] = scores[i];
			player[i][1] = ages[i];
		}
		// auto cmp = [](vector<int> a, vector<int> b) {
		//     return (a[0] <= b[0])  || (a[0] == b[0] && a[1] <= b[1]);
		// };
		// sort(player.begin(), player.end(), cmp);
		sort(player.begin(), player.end());
		vector<int> dp(n, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = i - 1; j >= 0; --j)
				if (player[j][1] <= player[i][1])
					dp[i] = max(dp[i], dp[j]);

			dp[i] += player[i][0];
			res = max(res, dp[i]);
		}

		return res;
	}
};
int main() {
	vector<int> scores({4, 5, 6, 5}), ages({2, 1, 2, 1});
	Solution ss;
	ss.qSort(scores, ages, 0, 3);
	for (auto a : scores)
		cout << a << " ";
	cout << "\n";
	for (auto b : ages)
		cout << b << " ";
	cout << endl;

	return 0;
}