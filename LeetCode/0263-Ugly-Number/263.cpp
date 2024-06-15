/*
LeetCode 263: Ugly Number
@Description:
Given an integer n, return true if n is an ugly number.

Ugly number is a positive number whose prime factors only include 2, 3, and/or 5.

type(n) = int
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：素因数分解即可
*/
class Solution {
public:
	bool isUgly(int n) {
		while (n > 1 && n % 5 == 0)
			n /= 5;
		while (n > 1 && n % 2 == 0)
			n /= 2;
		while (n > 1 && n % 3 == 0)
			n /= 3;
		return (n == 1);
	}
};
int main() { return 0; }