/*
 * @Date: 2024-01-24 10:19:01
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0000-Basic-Framework/排序算法/基数排序.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/**
 * @description: exp为10的幂，用于获取数字的第exp位
*/
void countingSort(vector<int>& arr, int exp) {
    const int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    // 统计每个数字出现的次数
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // 统计到当前数字为止，有多少个数被记录
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        // 用于找到当前数字在输出数组中的正确位置。
        // count 数组存储了每个数字出现的次数，因此 (arr[i] / exp) % 10 就是当前数字在 count 数组中的索引，
        // 而 count[(arr[i] / exp) % 10] - 1 则是该数字在输出数组中的索引。减去1是因为数组索引从0开始。
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}


void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}


int main() {


    return 0;
}