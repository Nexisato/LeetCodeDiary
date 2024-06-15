#include <bits/stdc++.h>
using namespace std;
/**
 * @brief
 * 滑動窗口模板題目
 *
 */
class Solution {
public:
	int minimumRecolors(string blocks, int k) {
		int n = blocks.size(), count = 0, res = n;
		int left = 0, right = 0;
		int whiteNum = 0, blackNum = 0;
		while (right < n) {
			if (blocks[right] == 'B')
				blackNum++;
			else if (blocks[right] == 'W')
				whiteNum++;
			if (right >= k - 1) {
				count = whiteNum;
				res = min(res, count);
				if (blackNum == k)
					return res;
				whiteNum -= (blocks[left] == 'W') ? 1 : 0;
				blackNum -= (blocks[left] == 'B') ? 1 : 0;
				left++;
			}
			right++;
		}
		return res;
	}
};
int main() {
	string blocks = "WBWBBBW";
	int k = 2;
	Solution ss;
	int res = ss.minimumRecolors(blocks, k);
	cout << res << endl;

	return 0;
}