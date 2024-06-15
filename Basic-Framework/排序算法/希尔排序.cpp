/*
 * @Date: 2024-01-24 09:10:58
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0000-Basic-Framework/排序算法/希尔排序.cpp
 * @Description:
 */
#include <iostream>
#include <vector>
using namespace std;

//【插入】
// 时间复杂度：最好O(n)，最坏O(n^2)
// 平均 O(n ^1.5)
// 空间复杂度 O(1)
// 不稳定

void shellSort(vector<int>& nums) {
	int n = nums.size();
	// 先 gap 分组，再插入排序
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; ++i) {
			for (int j = i - gap; j >= 0 && nums[j + gap] < nums[j]; j -= gap)
				swap(nums[j + gap], nums[j]);
		}
	}
}

int main() { return 0; }