/*
Description:
Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

    /*
    思路: 
        1. (调库侠)：降序快排，直接返回第k个索引 TC:O(nlogn) ，最好不要这么写
        2. 堆排序
    */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return sort(nums.begin(),nums.end(),greater<int>()),nums[k-1];
    }
};
int main(){

    return 0;
}