#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 直接比较 delta x 即可
 *
 */
class Solution {
public:
	int maxWidthOfVerticalArea(vector<vector<int>>& points) {
		int n = points.size();
		int res = 0;
		sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) -> bool { return a[0] <= b[0]; });
		res = 0;
		for (int i = 1; i < n; ++i) {
			int delta = points[i][0] - points[i - 1][0];
			res = max(res, delta);
		}

		return res;
	}
};
int main() { return 0; }