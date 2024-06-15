/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0012-Integer-to-Roman/12.cpp
 * @Description:
 */
/*
LeetCode 12: Integer to Roman
@Description:
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X
+ II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII.
Instead, the number four is written as IV. Because the one is before the five we subtract it making four.
The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is
used:
- I can be placed before V (5) and X (10) to make 4 and 9. 
- X can be placed before L (50) and C (100) to make 40 and 90. 
- C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

Constraints:
1 <= num <= 3999
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
思路：不同于13——Roman to Integer，这并不是一个简单的逆过程
罗马数字由7个单字母符号构成，每个符号对应一个单独的数值，由于减法规则的限制，我们增加额外6个复合符号用于减法使用
建立从大到小的映射表
*/
static const pair<int, string> table[] = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
                                          {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
                                          {5, "V"},    {4, "IV"},   {1, "I"}};
class Solution {
public:
	string intToRoman(int num) {
		string res = "";
		for (const auto& [val, symbol] : table) {
			while (num >= val) {
				num -= val;
				res += symbol;
			}
			if (num == 0)
				break;
		}
		return res;
	}
};
int main() {
	int num = 4396;
	Solution ss;
	string res = ss.intToRoman(num);
	cout << res << endl;
	return 0;
}