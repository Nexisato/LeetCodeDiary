/*
LeetCode 150: Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. 
That means the expression would always evaluate to a result, 
and there will not be any division by zero operation.

Constraints:
1 <= tokens.length <= 10^4
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
*/
#include <bits/stdc++.h>
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
            }
            else if (token == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            }
            else if (token == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a * b);
            }
            else if (token == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b / a);
            }
            else 
                st.push(stoi(token));
        }
        return st.top();
    }
};
int main() {

    return 0;
}