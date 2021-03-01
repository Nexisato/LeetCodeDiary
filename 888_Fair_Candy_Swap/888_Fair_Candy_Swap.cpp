/*
@LeetCode 888: Fair Candy Swap
@author: Nexisato
@Description:
Alice and Bob have candy bars of different sizes: A[i] is the size of the i-th bar of candy 
that Alice has, and B[j] is the size of the j-th bar of candy that Bob has.

Since they are friends, they would like to exchange one candy bar each so that after the exchange, 
they both have the same total amount of candy.  
(The total amount of candy a person has is the sum of the sizes of candy bars they have.)

Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, 
and ans[1] is the size of the candy bar that Bob must exchange.

If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.
 
Note:
1 <= A.length <= 10000
1 <= B.length <= 10000
1 <= A[i] <= 100000
1 <= B[i] <= 100000
It is guaranteed that Alice and Bob have different total amounts of candy.
It is guaranteed there exists an answer.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：双指针
1. 暴力法必定超时
2. sumA 和 sumB 是二者各自的累加和， sumA -sumB 是要弥补的差距，只需两元素差 delta = (sumA -sumB) / 2
3. 升序排序A，B，分别遍历两个数组中的元素xa, xb
- xa - xb == (sumA - sumB) / 2，找到结果
- xa - xb < delta ，增大 xa
- xa - xb > delta ，减小xb
*/
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int delta = (sumA - sumB) / 2;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            int tmp = A[i] - B[j];
            if (tmp == delta)
                return {A[i], B[j]};
            else if (tmp < delta)
                ++i;
            else
                ++j;
        }
        return {};
    }
};
int main() {

    return 0;
}