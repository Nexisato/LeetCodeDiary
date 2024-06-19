/*
LeetCode 84: Largest Rectangle in Histogram
@Description:
Given n non-negative integers representing the histogram's bar height where the width of
each bar is 1, find the area of largest rectangle in the histogram.

Constraints:
1 <= heights.length <= 10^5
0 <= heights[i] <= 10^4
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：单调栈
1. 对于某个高度，可以求得向左和向右的边界，求可以对该高度求一次面积
2. 遍历所有高度，即可得到最大面积
3. 使用单调栈，即可在出栈时得到前后边界并计算面积
*/
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int> s;
		int res = 0;
		heights.push_back(0);
		for (int i = 0; i < heights.size(); ++i) {
			while (!s.empty() && heights[s.top()] >= heights[i]) {
				int h = heights[s.top()];
				s.pop();
				if (s.empty())
					res = max(res, i * h);
				else
					res = max(res, (i - s.top() - 1) * h);
			}
			s.push(i);
		}
		return res;
	}
};
int main() { return 0; }