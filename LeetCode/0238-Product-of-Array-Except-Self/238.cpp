/*
 * @Date: 2024-02-02 15:22:36
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0238-Product-of-Array-Except-Self/238.cpp
 * @Description:
 */
#include <iostream>
#include <vector>
using namespace std;

// 别傻乎乎用除法
// 先算前缀积，再算后缀积
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		const int n = nums.size();
		if (n <= 1)
			return nums;
		vector<int> res(n, 1);
		res[0] = 1;
		for (int i = 1; i < n; ++i) {
			res[i] = nums[i - 1] * res[i - 1];
		}
		int back = 1;
		for (int j = n - 2; j >= 0; --j) {
			back *= nums[j + 1];
			res[j] *= back;
		}
		return res;
	}
};

int main() { return 0; }