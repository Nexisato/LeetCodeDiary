#include <bits/stdc++.h>
using namespace std;

//选择排序:O(n^2)，空间复杂度O(1)
//将第i个最小值放在第i轮循环的最前面
//不稳定
void selectionSort(vector<int>& nums) {
    int n = nums.size();
    int minIndex;
    for (int i = 0; i < n - 1; ++i) {
        minIndex = i;
        for (int j = i + 1; j < n; ++j)
            if (nums[minIndex] > nums[j])
                minIndex = j;
        swap(nums[i], nums[minIndex]);
    }
}

//二元选择排序：同时记录最小值和最大值
//时间复杂度O(n^2)，空间复杂度O(1)
void selectionSort_double(vector<int>& nums) {
    int n = nums.size();
    int minIndex, maxIndex;
    //i只需要遍历一半
    for (int i = 0; i < n / 2; ++i) {
        minIndex = i;
        maxIndex = i;
        for (int j = i + 1; j < n - i; ++j) {
            //最小值下标
            if (nums[minIndex] > nums[j])
                minIndex = j;
            //最大值下标
            if (nums[maxIndex] < nums[j])
                maxIndex = j;
        }
        //最大最小下标相等，则必定等于i，全数组大小相同
        if (minIndex == maxIndex) break;
        //最小的元素交换到首位
        swap(nums[minIndex], nums[i]);
        //若最大元素的下标为i，由于nums[i]和nums[minIndex]已交换，则更新maxIndex的值
        if (i == maxIndex)  maxIndex = minIndex;
        int LastIndex = n - 1 - i;
        swap(nums[maxIndex], nums[LastIndex]);
    }
}


int main() {


    return 0;
}