/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0136-Single-Number/136-Single-Number.cpp
 * @Description: 
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// 思路：采用异或写法
	//  任何数和0异或，结果仍是原来的数；任何数和其自身异或，结果是0
	//  异或运算满足交换律和结合律
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (vector<int>::size_type i = 0; i < nums.size(); i++) {
			result ^= nums[i];
		}
		return result;
	}
	void Print(vector<int>& nums) {
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it += 1) {
			cout << *(it) << endl;
		}
	}
};

int main() {
	vector<int> nums = {4, 1, 2, 1, 2};
	Solution ss;
	cout << ss.singleNumber(nums) << endl;

	return 0;
}