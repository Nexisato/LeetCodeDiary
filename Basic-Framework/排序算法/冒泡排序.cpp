/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0000-Basic-Framework/排序算法/冒泡排序.cpp
 * @Description:
 */
#include <iostream>
#include <vector>
using namespace std;

// 【交换】
//稳定
//第一种写法： O(n^2)，
void bubbleSort_1(vector<int>& nums) {
	int n = nums.size();
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < n - i - 1; ++j)
			if (nums[j] > nums[j + 1])
				swap(nums[j], nums[j + 1]);
}

//第二种写法：O(n^2)，最好的情况下O(n)
void bubbleSort_2(vector<int>& nums) {
	int n = nums.size();
	bool swapped = true;
	for (int i = 0; i < n - 1; ++i) {
		if (swapped == false)
			break;
		swapped = false;
		for (int j = 0; j < n - i - 1; ++j)
			if (nums[j] > nums[j + 1]) {
				swap(nums[j], nums[j + 1]);
				swapped = true;
			}
	}
}

//第三种写法：O(n^2)，最好的情况下O(n)
void bubbleSort_3(vector<int>& nums) {
	bool swapped = true;
	int lastIndexOfUnsortedElem = nums.size() - 1;
	while (swapped) {
		swapped = false;
		for (int i = 0; i < lastIndexOfUnsortedElem; ++i)
			if (nums[i] > nums[i + 1]) {
				swap(nums[i], nums[i + 1]);
				swapped = true;
			}
	}
}

int main() { return 0; }