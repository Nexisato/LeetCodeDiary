#include <bits/stdc++.h>
using namespace std;

//归并排序，稳定
//时间复杂度:O(nlogn)，空间复杂度：O(n)
void mergeSort(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return;
    vector<int> res(n);
    mergeSort(nums, 0, n - 1, res);
    
}
//对nums[start...end]的区间排序
void mergeSort(vector<int>& nums, int start, int end, vector<int>& res) {
    if (start == end)
        return;
    int mid = (start + end) / 2;
    mergeSort(nums, start, mid, res);
    mergeSort(nums, mid + 1, end, res);
    merge(nums, start, end, res);
}
//合并res的[start...mid]和[mid + 1...end]
void merge(vector<int>& nums, int start, int end, vector<int>& res) {
    int end1 = (start + end) / 2;
    int start2 = end1 + 1;
    int idx1 = start, idx2 = start2;
    while (idx1 <= end1 && idx2 <= end) {
        if (nums[idx1] <= nums[idx2])
            res[idx1 + idx2 - start2] = nums[idx1++];
        else
            res[idx1 + idx2 - start2] = nums[idx2++];
    }
    while (idx1 <= end1)
        res[idx1 + idx2 - start2] = nums[idx1++];
    while (idx2 <= end)
        res[idx1 + idx2 - start2] = nums[idx2++];
    //将res[start..end]拷贝回nums数组中
    while (start <= end)
        nums[start] = res[start++]; 
}


int main() {


    return 0;
}