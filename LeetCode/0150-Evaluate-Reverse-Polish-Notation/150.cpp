/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0150-Evaluate-Reverse-Polish-Notation/150.cpp
 * @Description:
 */
/*
LeetCode 150: Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another
expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid.
That means the expression would always evaluate to a result,
and there will not be any division by zero operation.

Constraints:
1 <= tokens.length <= 10^4
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range
[-200, 200].
*/
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/*
思路：RPN，操作数入栈，遇到操作符连弹2次栈，注意底层的元素为被减（除）数
*/
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
		int res = 0;
		for (string token : tokens) {
			if (token == "+") {
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				st.push(a + b);
			} else if (token == "-") {
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				st.push(b - a);
			} else if (token == "*") {
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				st.push(a * b);
			} else if (token == "/") {
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				st.push(b / a);
			} else
				st.push(stoi(token));
		}
		return st.top();
	}
};

class Solution_simplified {
public:
	int evalRPN(vector<string>& tokens) {
		using ll = long long;
		stack<ll> st;
		for (auto token : tokens) {
			if (token == "+" || token == "-" || token == "*" || token == "/") {
				ll num1 = st.top();
				st.pop();
				ll num2 = st.top();
				st.pop();
				if (token == "+")
					st.push(num2 + num1);
				else if (token == "-")
					st.push(num2 - num1);
				else if (token == "*")
					st.push(num2 * num1);
				else if (token == "/")
					st.push(num2 / num1);
			} else {
				st.push(stoll(token));
			}
		}
		return st.top();
	}
};
int main() { return 0; }