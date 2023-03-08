/*
@Description:
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
*/
#include <iostream>
using namespace std;
class Solution {
public:
    int fib(int n) {
        const int MODE = 1e9+7;
        if (n < 2)
            return n;
        int a = 0,b = 0,c = 1;
        int sum = 0;
        for(int i = 2; i <= n; ++i){
            a = b;
            b = c;
            c = (a + b) % MODE;
        }
        return c;
    }
};
int main() {

    return 0;
}