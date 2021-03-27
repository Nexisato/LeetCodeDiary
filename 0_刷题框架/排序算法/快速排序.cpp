#include <bits/stdc++.h>
using namespace std;

//快速排序，不稳定
//时间复杂度：平均O(nlogn)，最坏O(n^2)
//空间复杂度：平均O(logn)，最坏O(n)

void quickSort(vector<int> &nums) {
    int n = nums.size();
    quickSort(nums, 0, n - 1);
}
void quickSort(vector<int> &nums, int start, int end) {
    if (start >= end)
        return;
    //数组分区，获得中间值下标
    int mid = partition(nums, start, end);
    //用mid - 1而不是mid，实际上每一次遍历都可以把基准值放到最终对应位置上
    quickSort(nums, start, mid - 1);
    quickSort(nums, mid + 1, end);
}
//分区算法，选用第一个值作为基准
int partition(vector<int> &nums, int start, int end) {
    int pivot = nums[start];
    int l = start + 1, r = end;
    while (l < r) {
        //找到第一个大于基准数的位置
        while (l < r && nums[l] <= pivot) ++l;
        //找到第一个小于基准数的位置
        while (l < r && nums[r] >= pivot) --r;
        if (l < r) swap(nums[l], nums[r]);
        l++;
        r--;
    }
    swap(nums[start], nums[r]);
    return l;
}



int main() {

    return 0;
}