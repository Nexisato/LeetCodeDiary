/*
LeetCode: 412 Fizz Buzz
Description:
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number 
and for the multiples of five output “Buzz”. 
For numbers which are multiples of both three and five output “FizzBuzz”.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
1. 考虑多分支结构（条件简单时可用）
2. 字符串拼接
*/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        string fizz = "Fizz";
        string buzz = "Buzz";
        string both = fizz+buzz;
        vector<string> res;
        for (int i = 1; i<=n ; i++) {
            if ((i % 3 == 0) && (i % 5 == 0))
                res.push_back(both);
            else if (i % 3 == 0)
                res.push_back(fizz);
            else if (i % 5 == 0)
                res.push_back(buzz);
            else
                res.push_back(to_string(i));
        }
        return res;
    }
    vector<string> fizzBuzz_cat(int n) {
        vector<string> res;
        string output = "";
        for (int num = 1; num <= n; num++) {
            output = "";
            if (num % 3 == 0)
                output += "Fizz";
            if (num % 5 == 0)
                output += "Buzz";
            if (output == "")
                output += to_string(num);
            res.push_back(output);
        }
        return res;
    }
};
int main() {
    int num = 15;
    Solution ss;
    vector<string> res = ss.fizzBuzz_cat(num);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] <<endl;
    }
    return 0;
}