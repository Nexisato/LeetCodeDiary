/*
Description:
The Hamming distance between two integers is the number of positions 
at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance
*/
#include<iostream>
using namespace std;

class Solution {
public:
    //思路：位运算. 两个整数异或得到结果的1的个数.
    int hammingDistance(int x, int y) {
        int n=x^y;
        int count=0;
        while(n>0){
            count+=n&1;
            n>>=1;
        }
        return count;
    }
};

int main(){
    Solution  ss;
    int x=1,y=4;
    cout<<ss.hammingDistance(x,y);
    return 0;
}