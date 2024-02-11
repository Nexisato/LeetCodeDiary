/*
 * @Date: 2024-02-11 21:06:46
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0050-Pow-x-n/50.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long long b = n;
        if (b < 0) {
            x = 1 / x;
            b = -b;
        }
        while (b > 0) {
            if (b & 1)
                res *= x;
            x *= x;
            b >>= 1;
        }
        return res;
    }
};
int main() {

    return 0;
}