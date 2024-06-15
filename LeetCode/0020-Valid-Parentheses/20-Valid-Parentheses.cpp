/*
LeetCode: 20 Valid Parentheses
Description:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
0. 判断括号有效性，利用栈和哈希表进行遍历访问。
1. 关键规则：后遇到的左括号先闭合，因此可以将左括号放入栈顶
2. 遇到右括号时，取出栈顶的左括号判断能否闭合，
    若不是相同类型 或 栈中没有左括号，判定字符串无效
3. 利用哈希表存储映射关系，键为右括号，值为相同类型的左括号
4. 若栈中没有左括号，返回True，否则返回False
5. 由左右括号的成对匹配关系，字符串长度为奇数时，直接返回False
*/
class Solution {
public:
	bool isValid(string s) {
		if (s.size() % 2 == 1)
			return false;
		unordered_map<char, char> bracketPair = {{'}', '{'}, {']', '['}, {')', '('}};
		vector<char> left;
		for (char c : s) {
			if (bracketPair.count(c)) {
				if (left.empty() || left.back() != bracketPair[c])
					return false;
				left.pop_back();
			} else {
				left.emplace_back(c);
			}
		}
		return left.empty();
	}
};
int main() { return 0; }