/*
LeetCode 1004: Max Consecutive Ones III
@Descripton:
Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s. 

Note:
1 <= A.length <= 20000
0 <= K <= A.length
A[i] is 0 or 1 
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路： 滑动窗口 + 双指针
1. 当前窗口保存 1 出现的次数
2. 若1出现的次数与k之和大于等于窗口长度，则继续扩大窗口，否则缩小窗口，直到right指针到达数组尽头
*/
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int count = 0;
        int left = 0, right = 0;
        int maxL = 0;
        for (; right < A.size(); right++) {
            if (A[right])
                ++count;
            if (right - left + 1 > count + K) {
                count = (A[left] == 1) ? (count - 1) : count;
                left++;
            }
            maxL = max(maxL, right - left + 1);
        }
        return maxL;
    }
};
int main() {
    vector<int> A = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int K = 3;
    Solution ss;
    cout << ss.longestOnes(A, K) << endl;
    return 0;
}