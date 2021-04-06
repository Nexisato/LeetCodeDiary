/*
LeetCode 92: Sort an array
@Description:
Given an array of integers nums, sort the array in ascending order.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
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
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quickSort(nums, 0, n - 1);
        return nums;
    }
};
int main() {

    return 0;
}