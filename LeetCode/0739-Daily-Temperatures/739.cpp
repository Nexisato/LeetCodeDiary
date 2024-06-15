/*
LeetCode 739: Daily Temperatures
@Description:
Given a list of daily temperatures T, return a list such that, for each day in the input,
tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is
possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1,
1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000].
Each temperature will be an integer in the range [30, 100].
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：[FooBar]单调栈
1. 构造单调递减栈
2. 数组当前下标对应的元素大于栈顶对应的元素时，发生出栈
3. 根据单调递减栈的性质，发生出栈时，要换入的元素就是自栈顶下标往后，大于栈顶的第一个元素
*/
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		int n = T.size();
		vector<int> st;
		vector<int> res(n, 0);
		for (int i = 0; i < n; ++i) {
			while (!st.empty() && T[st.back()] < T[i]) {
				int idx = st.back();
				st.pop_back();
				res[idx] = i - idx;
			}
			st.emplace_back(i);
		}
		return res;
	}
};
int main() { return 0; }