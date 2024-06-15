/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0017-Letter-Combinations-of-a-Phone-Number/17.cpp
 * @Description:
 */
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief
 * 回溯法
 * 将键盘上数字与对应的几个字符映射
 *
 */
class Solution {
private:
	const string number[10] = {
	    "",     // 0
	    "",     // 1
	    "abc",  // 2
	    "def",  // 3
	    "ghi",  // 4
	    "jkl",  // 5
	    "mno",  // 6
	    "pqrs", // 7
	    "tuv",  // 8
	    "wxyz", // 9
	};

private:
	vector<string> res;
	string s;
	void backtracking(const string& digits, int startIndex) {
		if (s.size() == digits.size()) {
			res.push_back(s);
			return;
		}
		int curDigit = digits[startIndex] - '0';
		string curStr = number[curDigit];
		for (int i = 0; i < curStr.size(); ++i) {
			s.push_back(curStr[i]);
			backtracking(digits, startIndex + 1);
			s.pop_back();
		}
	}

public:
	vector<string> letterCombinations(string digits) {
		res.clear();
		s.clear();
		if (digits.size() == 0)
			return res;
		backtracking(digits, 0);
		return res;
	}
};
int main() { return 0; }