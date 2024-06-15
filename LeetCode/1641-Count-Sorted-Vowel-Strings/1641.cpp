#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * n个球m个盒子，盒子可以置空的隔板法 C(n + m - 1, m - 1)
 *
 */
class Solution {
public:
	int countVowelStrings(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(5, 0));
		for (int i = 0; i < 5; ++i)
			dp[1][i] = 1;

		for (int i = 2; i <= n; ++i) {
			for (int j = 0; j < 5; ++j) {
				dp[i][j] = accumulate(dp[i - 1].begin(), dp[i - 1].begin() + j + 1, 0);
			}
		}
		int res = accumulate(dp[n].begin(), dp[n].end(), 0);
		return res;
	}
};
int main() {
	int n = 33;
	Solution ss;
	int res = ss.countVowelStrings(n);
	cout << res << endl;

	return 0;
}