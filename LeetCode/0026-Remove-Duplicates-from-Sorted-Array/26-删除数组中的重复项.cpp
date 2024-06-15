/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0026-Remove-Duplicates-from-Sorted-Array/26-删除数组中的重复项.cpp
 * @Description:
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int count = 1;
		int size = nums.size();
		for (int i = 1; i < size; ++i)
			if (nums[i] != nums[i - 1]) {
				nums[count++] = nums[i];
			}
		nums.erase(nums.begin() + count, nums.end());
		return count;
	}
	void Print(vector<int>& nums) {
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it += 1) {
			cout << *(it) << endl;
		}
	}
	int removeDuplicates_faster(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int slowPtr = 0, fastPtr = 0, n = nums.size();
		for (; fastPtr < n - 1; ++fastPtr) {
			if (nums[fastPtr] != nums[fastPtr + 1]) {
				++slowPtr;
				nums[slowPtr] = nums[fastPtr + 1];
			}
		}
		return slowPtr + 1;
	}
};

int main() {
	Solution ss;
	vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	cout << ss.removeDuplicates_faster(nums) << endl;
	ss.Print(nums);
	return 0;
}