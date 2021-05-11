/*
LeetCode 4: Median of Two Sorted Arrays
@Description:
Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays.

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    思路：不合并数组，直接找到计数中位数
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int mid1 = (m + n) / 2, mid2 = (m + n) / 2 - 1;
        int i = 0, j = 0, count = 0;
        double num1 = 0, num2 = 0, num = 0;
        while (i < m || j < n) {
            int x = (i > m - 1) ? INT32_MAX : nums1[i];
            int y = (j > n - 1) ? INT32_MAX : nums2[j];
            if (x < y) {
                num = x;
                i++;
            }
            else {
                num = y;
                j++;
            }
            if (count == mid2)
                num2 = num;
            if (count == mid1)
                num1 = num;
            count++;
        }
        if ((m + n) % 2)
            return (double) num1;
        else 
            return double(num1 + num2) / 2;
    }
};
/*
思路：二分查找
1. 寻找第K小的元素
    - 比较  pivot1 = nums1[k/2-1] 和   pivot2 = nums2[k/2-1]
    - 两数组中小于 pivot1(2) 的元素各自共计 k/2 - 1个
    - pivot = min(pivot1, pivot2)，则两数组中小于等于pivot的元素共计不会超过(k/2-1)+(k/2-1) <= k-2个
    - 因而pivot在合并数组中最大为第k-1小的元素
    - 若pivot == pivot1，则移除nums1数组中前[0...k/2-1]个元素；
    - 若pivot==pivot2，则移除nums2数组中前[0...k/2-1]个元素。删除后对k值进行更新
*/
class Solution_bs {
private:
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int idx1 = 0, idx2 = 0;
        while (true) {
            if (idx1 == m)
                return nums2[idx2 + k - 1];
            if (idx2 == n)
                return nums1[idx1 + k - 1];
            if (k == 1)
                return min(nums1[idx1], nums2[idx2]);
            int new_idx1 = min(idx1  + k / 2 - 1, m - 1);
            int new_idx2 = min(idx2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[new_idx1], pivot2 = nums2[new_idx2];
            if (pivot1 <= pivot2) {
                k -= new_idx1 - idx1 + 1;
                idx1 = new_idx1 + 1;
            }
            else {
                k -= new_idx2 - idx2 + 1;
                idx2 = new_idx2 + 1;
            }
        }
    }
public:
   double findMedianSortedArrays_bs(vector<int>& nums1, vector<int>& nums2) {
       int N = nums1.size() + nums2.size();
       if (N % 2)
        return (double)getKthElement(nums1, nums2, (N + 1) / 2);
        else {
            return double(getKthElement(nums1, nums2, N / 2) + getKthElement(nums1, nums2, N / 2 + 1)) / 2;
        }
   }
};

int main() {

    return 0;
}