/*
LeetCode 992: Subarrays with K different Integers
@Description:
Given an array A of positive integers, call a (contiguous, not necessarily distinct) 
subarray of A good if the number of different integers in that subarray is exactly K.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of A.
Note:
1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：滑动窗口
可以证明：对于任意一个右端点，能够与其对应的左端点们必定相邻
同时可以发现：当右端点向右移动时，左端点区间同时向右移动
维护两个左指针 [left1, left2)：
· 第一个左指针表示极大的包含K个不同整数的区间的左端点
· 第二个左指针表示极大的包含K - 1个不同整数的区间的左端点
此时，子数组计数问题转化为左区间计数问题
*/

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int N = A.size(), res = 0;
        int left1 = 0, left2 = 0, right = 0;
        int cnt1 = 0, cnt2 = 0;
        unordered_map<int, int> table1, table2;
        while (right < N) {
            if (table1[A[right]] == 0)
                ++cnt1;
            ++table1[A[right]];
            if (table2[A[right]] == 0)
                ++cnt2;
            ++table2[A[right]];
            while (cnt1 > K) 
                if (--table1[A[left1++]] == 0)
                    --cnt1;
            while (cnt2 > K - 1)
                if (--table2[A[left2++]] == 0)
                    --cnt2;
            res += left2 - left1;
            right++;
        }
        return res;
    }
};
int main() {

    return 0;
}