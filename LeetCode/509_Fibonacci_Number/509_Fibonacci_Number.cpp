/*
LeetCode: 509 Fibonacci Number
Description:
The Fibonacci numbers, commonly denoted F(n) form a sequence, 
called the Fibonacci sequence, such that each number is the sum of the two preceding ones, 
starting from 0 and 1. 

Given n, calculate F(n)

Constraints:
1 <= n <= 30
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
        int res;
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else {
            int f_a = 0, f_b = 1;
            while ( --n) {
                res = f_b + f_a;
                f_a = f_b;
                f_b = res;
                
            }
        }
        return res;
    }
};
int main() {
    Solution ss;
    cout << ss.fib(3) <<endl;
    return 0;
}