/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0000-Basic-Framework/排序算法/堆排序.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
using namespace std;

// 【选择】
// 堆排序
// 时间复杂度：O(nlogn)(always)，空间复杂度：O(1)
// 不稳定

// 最大堆的下沉操作，目的是将第 i 个元素下沉到合适的位置
void siftDown(vector<int>& nums, int i, int len) {
    while (i * 2 + 1 < len) {
        int child = i * 2 + 1;
        if (child + 1 < len && nums[child + 1] > nums[child])
            ++child;
        if (nums[i] > nums[child])
            break;
        swap(nums[i], nums[child]);
        i = child;
    }

}
// 建堆
void buildHeap(vector<int>& nums) {
    int n = nums.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        siftDown(nums, i, n);
}

// 每次将最大的元素放到最后，然后对剩下的元素进行下沉操作
void heapSort(vector<int>& nums) {
    buildHeap(nums);
    int n = nums.size();
    for (int last = n - 1; last >= 0; --last) {
        swap(nums[0], nums[last]);
        siftDown(nums, 0, last);
    }
}



int main() {


    return 0;
}