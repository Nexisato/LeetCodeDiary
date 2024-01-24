/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0088-Merge-Sorted-Array/88-Merge.cpp
 * @Description: 
 */
/*
Description: LeetCode:88
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one
sorted array.

Note:
The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space
(size that is equal to m + n) to hold additional elements from nums2.

Constraints:
    -10^9 <= nums1[i], nums2[i] <= 10^9
    nums1.length == m + n
    nums2.length == n
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 思路：前向双指针
    // 时间复杂度: O(m+n) 空间复杂度:O(m)
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> copy(nums1);
        int p1 = 0, p2 = 0;
        int p = 0;
        while (p1 < m && p2 < n)
            nums1[p++] = (copy[p1] < nums2[p2]) ? copy[p1++] : nums2[p2++];
        /*
        if(p1<m)
            nums1.insert(nums1.begin()+p,copy.begin()+p1,copy.begin()+m);
        if(p2<n)
            nums1.insert(nums1.begin()+p,nums2.begin()+p2,nums2.begin()+n);
        */
        while (p1 < m)
            nums1[p++] = copy[p1++];
        while (p2 < n)
            nums1[p++] = nums2[p2++];
    }
    void merge_simple(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int p = m + n - 1;
        while (p1 >= 0 && p2 >= 0)
            nums1[p--] = (nums1[p1] < nums2[p2]) ? nums2[p2--] : nums1[p1--];
        while (p2 >= 0)
            nums1[p--] = nums2[p2--];
    }
};
int main() {

    vector<int> nums1 = {2, 3, 66};
    vector<int> nums2 = {7, 11, 13, 45, 57};
    Solution ss;
    ss.merge(nums1, 3, nums2, 5);
    // nums1.insert(nums1.begin()+1,nums2.begin()+2,nums2.end());
    for (int i = 0; i < nums1.size() + nums2.size(); i++)
        cout << nums1[i] << " ";
    return 0;
}