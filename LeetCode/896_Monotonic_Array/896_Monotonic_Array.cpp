/*
LeetCode 986: Monotonic Array
@Description:
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  
An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.

Note:
1 <= A.length <= 50000
-100000 <= A[i] <= 100000
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：两次遍历
做好inc和dec标记，初始值设定为true，一旦有相应的dec或inc的情况就设置为false(这样无需考虑=0的情况)
*/
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() == 1) return true;
        int n = A.size();
        bool inc = true, dec = true;
        for (int i = 1; i < n; ++i) {
            if (A[i] > A[i - 1])
                dec = false;
            if (A[i] < A[i - 1])
                inc = false;
        }     
        return inc | dec;
    }
};
int main() {


    return 0;
}