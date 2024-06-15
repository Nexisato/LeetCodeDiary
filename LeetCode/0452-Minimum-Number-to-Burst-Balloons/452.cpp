/*
 * @Date: 2024-01-20 11:31:39
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0452-Minimum-Number-to-Burst-Balloons/452.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		sort(points.begin(), points.end());
		const int n = points.size();
		int res = 1;
		int left = points[0][0], right = points[0][1];

		// 也是只考虑重叠区间的右端点
		for (int i = 1; i < n; ++i) {
			if (points[i][0] <= right) {
				left = points[i][0];
				right = min(right, points[i][1]);
			} else {
				++res;
				left = points[i][0];
				right = points[i][1];
			}
		}

		return res;
	}
};
int main() { return 0; }