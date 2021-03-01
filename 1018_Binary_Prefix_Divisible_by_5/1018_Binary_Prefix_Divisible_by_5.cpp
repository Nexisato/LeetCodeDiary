/*
LeetCode: 1018 Binary Prefix Divisible by 5
Description:
Given an array A of 0s and 1s, consider N_i: the i-th subarray from A[0] to A[i] 
interpreted as a binary number (from most-significant-bit to least-significant-bit.)

Return a list of booleans answer, where answer[i] is true if and only if N_i is divisible by 5.

Note:
1 <= A.length <= 30000
A[i] is 0 or 1
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
1. 模拟
    将二进制数组转化为整数，再模5判断，可以直接得到结果
    然而，A.length 最长可达30000，很容易溢出
    因此每次计算时，不需要保留二进制序列转化为整数 N 的值，只需要保留 N 对 5 的模即可，
    模的更新公式与进制数码更新公式相同
*/
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> flags;
        int res = 0;
        int N = A.size();
        for (int i = 0; i < N; i++) {
            /*
            res = res * 2 + A[i];
            if (res % 5 == 0)
                flag = true;
            */
            res = ((res << 1) + A[i]) % 5;
            flags.push_back(res == 0);
        }
        return flags;
    }
};

int main() {
    
    return 0;
}