#include <bits/stdc++.h>
using namespace std;

//插入排序，稳定
//时间复杂度：O(n^2)；空间复杂度O(1)
void insertionSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        int curNum = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > curNum) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = curNum;
    }
}

int main() {


    return 0;
}