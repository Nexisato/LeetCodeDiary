#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int mergeCount(int l, int r, vector<int>& nums, vector<int>& tmp) {
        if (l >= r) return 0;
        int mid = l + ((r - l) >> 1);
        int res = mergeCount(l, mid, nums, tmp) + mergeCount(mid + 1, r, nums, tmp);
        int i = l, j = mid + 1;
        
        for (int k = l; k <= r; ++k)
            tmp[k] = nums[k];
        
        for (int k = l; k <= r; ++k) {
            if (i == mid + 1)
                nums[k] = tmp[j++]; //合并右边多余的数组
            else if (j == r + 1 || tmp[i] <= tmp[j]) // 合并左边多余的数组 & 非逆序数组
                nums[k] = tmp[i++];
            else {
                nums[k] = tmp[j++];
                res += mid - i + 1; // 左边的数组已经排序好了，因此从 nums[i-m] 都是大于 nums[j] 的
            }
        }
        return res;
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(nums.size());
        return mergeCount(0, n - 1, nums, tmp);
    }
};
int main() {

    return 0;
}