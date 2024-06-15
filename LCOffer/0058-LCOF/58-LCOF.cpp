/**
 * @file 58_LCOF.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-15
 *
 * @copyright Copyright (c) 2023
 *
 * 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
 * 比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

 *  1 <= k < s.length <= 10000
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * 思路，不开辟额外空间，旋转三次即可
 *
 */
class Solution {
public:
	string reverseLeftWords(string s, int n) {
		reverse(s.begin(), s.begin() + n);
		reverse(s.begin() + n, s.end());
		reverse(s.begin(), s.end());
		return s;
	}
};
