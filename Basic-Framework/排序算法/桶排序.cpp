/*
 * @Date: 2024-01-24 10:05:39
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0000-Basic-Framework/排序算法/桶排序.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// 非常占空间
void bucketSort(vector<int>& nums) {
    int n = nums.size();

    int maxVal = *max_element(nums.begin(), nums.end());
    int minVal = *min_element(nums.begin(), nums.end());

    int bucketSize = (maxVal - minVal) + 1;
    vector<int> bucket(bucketSize, 0);
    
    for (int i = 0; i < n; ++i) {
        int idx = (nums[i] - minVal);
        bucket[idx]++;
    }

    int idx = 0;
    for (int i = 0; i < bucketSize; ++i) {
        while (bucket[i] > 0) {
            nums[idx++] = i + minVal;
            --bucket[i];
        }
    }
}

int main() {

    return 0;
}