/*
LeetCode: 5654 Maximum Number Of Balls in a Box
Description:
You are working in a ball factory where you have n balls numbered from lowLimit up to highLimit inclusive 
(i.e., n == highLimit - lowLimit + 1), and an infinite number of boxes numbered from 1 to infinity.

Your job at this factory is to put each ball in the box with a number 
equal to the sum of digits of the ball's number. 
For example, the ball number 321 will be put in the box number 3 + 2 + 1 = 6 
and the ball number 10 will be put in the box number 1 + 0 = 1.

Given two integers lowLimit and highLimit, return the number of balls in the box with the most balls.

Constraints:
1 <= lowLimit <= highLimit <= 10^5
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
暴力枚举即可
*/
class Solution {
    const int MAX = 50;
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> sum(MAX, 0);
        for (int num = lowLimit; num <= highLimit; num++) {
            int tot = 0 , tmp = num;
            while (tmp != 0) {
                tot += (tmp % 10);
                tmp /= 10;
            }
            sum[tot]++;
        }
        int res = 0;
        for (int num : sum) 
            res = max(res, num);
        return res; 
    }
};

int main() {

    return 0;
}