/*
Description:
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    //思路：爬到第n层阶梯需要f(n)种方法，则 f(n) = f(n-1)+f(n-2)
    int climbStairs(int n) {
        int a=0,b=0,c=1;
        int sum=0;
        for(int i=1;i<=n;++i){
            a=b;
            b=c;
            c=a+b;
        }
        return c;
    }
};

int main(){
    Solution ss;
    cout<<ss.climbStairs(3);

    return 0;
}