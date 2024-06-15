/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0013-Roman-to-Integer/13-Roman-to-Integer.cpp
 * @Description:
 */
/*
LeetCode: 13 Roman to Integer
Description:
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X
+ II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written as IV.
Because the one is before the five we subtract it making four.
The same principle applies to the number nine, which is written as IX.
There are six instances where subtraction is used:
I —— 1
V —— 5
X —— 10
L —— 50
C —— 100
D —— 500
M —— 1000
-I can be placed before V (5) and X (10) to make 4 and 9. 
-X can be placed before L (50) and C (100) to make 40 and 90. 
-C can be placed before D (500) and M (1000) to make 400 and 900.
-Given a roman numeral, convert it to an integer.

Constraints:
-1 <= s.length <= 15
-s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
-It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
/*
思路：
1. 使用Hashmap，将对应的罗马数字转化为整数
2. 规律：比较两个字符，若左边的字符小于右边的字符，则值等于右边字符减去左边字符，反之相加即可
3. 从左到右遍历字符串，进行2中的对比，迭代相加得到结果即可
*/
class Solution {
public:
	int romanToInt(string s) {
		int res = 0;
		unordered_map<char, int> romanAlphabet = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
		                                          {'C', 100}, {'D', 500}, {'M', 1000}};
		for (int i = 0; i < s.length(); i++) {
			if ((i < s.length() - 1) && (romanAlphabet[s[i]] < romanAlphabet[s[i + 1]]))
				res -= romanAlphabet[s[i]];
			else
				res += romanAlphabet[s[i]];
		}
		return res;
	}
};

int main() {
	string tmp = "MCMXCIV";
	Solution ss;
	cout << ss.romanToInt(tmp) << endl;
	return 0;
}