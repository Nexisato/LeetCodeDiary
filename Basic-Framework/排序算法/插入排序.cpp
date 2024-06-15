/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0000-Basic-Framework/排序算法/插入排序.cpp
 * @Description:
 */
#include <iostream>
#include <vector>
using namespace std;

//【插入】
//插入排序，稳定
// 平均时间复杂度：O(n^2)；空间复杂度O(1)
// 最好情况：O(n)，最坏情况：O(n^2)
void insertionSort(vector<int>& nums) {
	int n = nums.size();
	for (int i = 1; i < n; ++i) {
		for (int j = i - 1; j >= 0 && nums[j + 1] < nums[j]; --j)
			swap(nums[j + 1], nums[j]);
	}
}

int main() { return 0; }