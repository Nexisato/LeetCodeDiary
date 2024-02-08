/*
 * @Date: 2024-02-08 09:07:00
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0224-Basic-Calculator/224.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <ctype.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int res = 0;

        stack<int> stk;
        int sign = 1;
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '+') {
                res += sign * num;
                sign = 1;
                num = 0;
            } else if (s[i] == '-') {
                res += sign * num;
                sign = -1;
                num = 0;
            } else if (s[i] == '(') {
                stk.push(res);
                stk.push(sign);
                res = 0;
                sign = 1;
            } else if (s[i] == ')') {
                res += sign * num;
                res *= stk.top();
                stk.pop();
                res += stk.top();
                stk.pop();
                num = 0;
            }
        }
        res += sign * num;


        return res;
    }
};
int main() {


    return 0;
}