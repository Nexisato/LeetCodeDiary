/*
LeetCode 5680: Find Nearest Point That Has the Same X or Y Coordinate
@Description:
You are given two integers, x and y, which represent your current location on a Cartesian grid: (x, y).
You are also given an array points where each points[i] = [ai, bi] represents that a point exists at (ai, bi).
A point is valid if it shares the same x-coordinate or the same y-coordinate as your location.

Return the index (0-indexed) of the valid point with the smallest Manhattan distance
from your current location. If there are multiple, return the valid point with the smallest index.
If there are no valid points, return -1.

The Manhattan distance between two points (x1, y1) and (x2, y2) is abs(x1 - x2) + abs(y1 - y2)

Constraints:
1 <= points.length <= 10^4
points[i].length == 2
1 <= x, y, ai, bi <= 10^4
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：直接遍历即可
*/
class Solution {
public:
	int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
		int idx = -1;
		int n = points.size();
		int dis = INT32_MAX;
		for (int i = 0; i < n; ++i) {
			int a = points[i][0], b = points[i][1];
			if (a == x || b == y) {
				int delta = abs(x - a) + abs(y - b);
				if (delta < dis) {
					dis = delta;
					idx = i;
				}
			}
		}
		return idx;
	}
};
int main() { return 0; }