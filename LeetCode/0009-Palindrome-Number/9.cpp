/*
 * @Date: 2024-02-06 16:23:10
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0009-Palindrome-Number/9.cpp
 * @Description:
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		long long y = 0, t = x;
		while (t) {
			y = y * 10 + t % 10;
			t /= 10;
		}
		return y == x;
	}
};
int main() { return 0; }