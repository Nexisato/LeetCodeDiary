/*
 * @Date: 2024-01-18 14:52:28
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2171_Removing_Minimum_Number_of_Magic_Beans/2171.cpp
 * @Description:
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	long long minimumRemoval(vector<int>& beans) {
		// 以某袋豆子的数量 x 为锚点，小于它的清空，大于的拿走多余部分
		const int n = beans.size();
		sort(beans.begin(), beans.end());
		long long sum = accumulate(beans.begin(), beans.end(), 0LL);
		long long res = sum;
		for (int i = 0; i < n; ++i)
			res = min(res, sum - ((long long)beans[i] * (n - i)));
		return res;
	}
};
int main() { return 0; }