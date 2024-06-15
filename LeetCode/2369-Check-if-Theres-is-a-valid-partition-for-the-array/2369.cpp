/*
 * @Date: 2024-03-01 20:07:46
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2369-Check-if-Theres-is-a-valid-partition-for-the-array/2369.cpp
 * @Description:
 */
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool validPartition(vector<int>& nums) {
		const int n = nums.size();
		auto isValid = [](vector<int>& arr, int l, int r) -> bool {
			int d = r - l;
			if (d != 1 && d != 2)
				return false;
			if (d == 1)
				return arr[l] == arr[r];
			else if (d == 2) {
				bool isEqual = (arr[l] == arr[l + 1]) && (arr[l + 1] == arr[r]);
				bool isAscend = (arr[l + 1] == arr[l] + 1) && (arr[r] == arr[l + 1] + 1);
				return isEqual || isAscend;
			}
			return false;
		};
		if (n <= 3)
			return isValid(nums, 0, n - 1);
		vector<bool> dp(n, false);
		dp[1] = isValid(nums, 0, 1);
		dp[2] = isValid(nums, 0, 2);
		// dp[i] 以 nums[i] 结尾的数组能否构成划分
		for (int i = 3; i < n; ++i) {
			dp[i] = (dp[i - 3] && isValid(nums, i - 2, i)) || (dp[i - 2] && isValid(nums, i - 1, i));
		}
		return dp[n - 1];
	}
};
int main() { return 0; }