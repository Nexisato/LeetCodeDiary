/*
 * @Date: 2024-01-23 10:02:28
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0135-Candy/135.cpp
 * @Description:
 *
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
	// 先从左到右遍历一遍，如果右边的评分比左边的高，那么右边的糖果数就是左边的糖果数加1；
	// 再从右到左遍历一遍，如果左边的评分比右边的高，并且左边的糖果数不大于右边的糖果数，那么左边的糖果数就是右边的糖果数加1。
	int candy(vector<int>& ratings) {
		const int n = ratings.size();
		vector<int> candy(n, 0);
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0 && ratings[i] > ratings[i - 1]) {
				candy[i] = candy[i - 1] + 1;
			} else {
				candy[i] = 1;
			}
		}
		for (int j = n - 1; j >= 0; --j) {
			if (j < n - 1 && ratings[j] > ratings[j + 1]) {
				candy[j] = max(candy[j], candy[j + 1] + 1);
			}
			res += candy[j];
		}

		return res;
	}
};
int main() {
	Solution sol;
	vector<int> ratings = {1, 3, 2, 2, 1};
	cout << sol.candy(ratings) << endl;

	return 0;
}