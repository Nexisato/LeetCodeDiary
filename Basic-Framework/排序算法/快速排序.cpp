/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0000-Basic-Framework/排序算法/快速排序.cpp
 * @Description:
 */
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

// 【交换】
// 快速排序，不稳定
// 时间复杂度：平均O(nlogn)，最坏O(n^2)
// 空间复杂度：平均O(logn)，最坏O(n)

// 元素开头作为 pivot，可以随机选择进行优化
void quickSort(vector<int>& nums, int start, int end) {
	if (start >= end)
		return;
	int pivot = nums[start];
	int l = start, r = end;
	while (l < r) {
		while (l < r && nums[r] >= pivot)
			--r;
		while (l < r && nums[l] <= pivot)
			++l;
		if (l < r)
			swap(nums[l], nums[r]);
	}
	swap(nums[start], nums[l]);
	quickSort(nums, start, l - 1);
	quickSort(nums, l + 1, end);
}

// 随机版
int randomPartition(vector<int>& nums, int start, int end) {
	int pivot = rand() % (end - start + 1) + start;
	swap(nums[pivot], nums[start]);
	pivot = nums[start];
	int l = start, r = end;
	while (l < r) {
		while (l < r && nums[r] >= pivot)
			--r;
		while (l < r && nums[l] <= pivot)
			++l;
		if (l < r)
			swap(nums[l], nums[r]);
	}
	swap(nums[start], nums[l]);
	return l;
}
void quickSort_rand(vector<int>& nums, int start, int end) {
	if (start >= end)
		return;
	int pivotIdx = randomPartition(nums, start, end);
	quickSort_rand(nums, start, pivotIdx - 1);
	quickSort_rand(nums, pivotIdx + 1, end);
}

// 尾递归优化版
void quickSort_tail(vector<int>& nums, int start, int end) {
	while (start < end) {
		int pivotIdx = randomPartition(nums, start, end);
		// 优化：尾递归
		// 递归调用的时候，总是先递归较短的那个分区，然后通过循环处理较长的分区
		if (pivotIdx - start < end - pivotIdx) {
			quickSort_tail(nums, start, pivotIdx - 1);
			start = pivotIdx + 1;
		} else {
			quickSort_tail(nums, pivotIdx + 1, end);
			end = pivotIdx - 1;
		}
	}
}
int main() { return 0; }