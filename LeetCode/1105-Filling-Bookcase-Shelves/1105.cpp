#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * 思路：
 *
 *
 */
class Solution {
public:
	int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
		const int n = books.size();
		vector<int> dp(n + 1, 1000000);
		dp[0] = 0;
		for (int i = 1; i <= n; ++i) {
			int tmpWidth = 0, tmpHeight = 0;
			for (int j = i; j > 0; --j) {
				tmpWidth += books[j - 1][0];
				if (tmpWidth > shelfWidth)
					break;
				tmpHeight = max(tmpHeight, books[j - 1][1]);
				dp[i] = min(dp[i], dp[j - 1] + tmpHeight);
			}
		}
		return dp[n];
	}
};
int main() { return 0; }