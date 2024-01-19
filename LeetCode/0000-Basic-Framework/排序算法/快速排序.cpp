#include <iostream>
#include <vector>
using namespace std;

// 快速排序，不稳定
// 时间复杂度：平均O(nlogn)，最坏O(n^2)
// 空间复杂度：平均O(logn)，最坏O(n)

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

int main() {
    return 0;
}