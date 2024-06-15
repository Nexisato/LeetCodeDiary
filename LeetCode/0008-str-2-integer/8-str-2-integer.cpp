/*
Description:
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary
until the first non-whitespace character is found.

Then, starting from this character takes an optional initial plus or
minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those
that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number,
or if no such sequence exists because either str is empty or it contains only whitespace characters,
no conversion is performed.
If no valid conversion could be performed, a zero value is returned

Note:
Only the space character ' ' is considered a whitespace character.
Assume we are dealing with an environment that could only store
integers within  the 32-bit signed integer range: [−2^31,  2^31 − 1].
If the numerical value is out of the range of representable values, 2^31 − 1 or −2^31 is returned.
 
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 思路：根据序列中的每一个字符，我们引入有限状态机，每输入一个不同种类的序列都会进入不同的状态.
class Automation {
	string state = "start";
	//前者可以根据不同的输入向后者vector中转换的状态

	unordered_map<string, vector<string>> table = {{"start", {"start", "signed", "in_number", "end"}},
	                                               {"signed", {"end", "end", "in_number", "end"}},
	                                               {"in_number", {"end", "end", "in_number", "end"}},
	                                               {"end", {"end", "end", "end", "end"}}};
	//四种输入分别为： [space] [+/-] [number] [other]
	int get_col(char c) {
		if (isspace(c))
			return 0;
		if (c == '+' or c == '-')
			return 1;
		if (isdigit(c))
			return 2;
		return 3;
	}

public:
	int sign = 1;
	long long ans = 0;

	void get(char c) {
		state = table[state][get_col(c)];
		if (state == "in_number") {
			ans = ans * 10 + c - '0';
			ans = (sign == 1) ? min(ans, (long long)INT32_MAX) : min(ans, -(long long)INT32_MIN);
		} else if (state == "signed")
			sign = (c == '+') ? 1 : -1;
	}
};
class Solution {
public:
	int myAtoi(string s) {
		Automation auto_mation;
		for (char c : s)
			auto_mation.get(c);
		return auto_mation.sign * auto_mation.ans;
	}
};

int main() {
	Solution ss;
	string s = "   -42";
	cout << ss.myAtoi(s);
	return 0;
}