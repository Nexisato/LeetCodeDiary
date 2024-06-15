/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0000-Basic-Framework/排序算法/归并排序.cpp
 * @Description:
 */
#include <iostream>
#include <vector>
using namespace std;

//归并排序，稳定
//时间复杂度:O(nlogn)，空间复杂度：O(n)
void mergeSort(vector<int>& nums) {
	int n = nums.size();
	if (n == 0)
		return;
	vector<int> res(n);
	mergeSort(nums, 0, n - 1, res);
}

// 长度小的话直接用插入排序
void insertSort(vector<int>& nums, int start, int end) {
	for (int i = start + 1; i <= end; ++i) {
		for (int j = i - 1; j >= 0 && nums[j] > nums[j + 1]; --j)
			swap(nums[j + 1], nums[j]);
	}
}

//对nums[start...end]的区间排序
void mergeSort(vector<int>& nums, int start, int end, vector<int>& tmp) {
	if (start >= end)
		return;
	int mid = start + ((end - start) >> 1);
	mergeSort(nums, start, mid, tmp);
	mergeSort(nums, mid + 1, end, tmp);

	// 用辅助数组合并，别直接返回 res
	for (int i = start; i <= end; ++i)
		tmp[i] = nums[i];

	for (int cur = start, i1 = start, i2 = mid + 1; cur <= end; ++cur) {
		if (i1 == mid + 1 || (i2 <= end && tmp[i1] > tmp[i2]))
			nums[cur] = tmp[i2++];
		else if (i2 == end + 1 || tmp[i1] <= tmp[i2])
			nums[cur] = tmp[i1++];
	}
}

int main() { return 0; }