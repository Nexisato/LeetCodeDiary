/*
 * @Date: 2024-02-05 09:21:44
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0067-Add-Binary/67.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i--] - '0';
            }
            if (j >= 0) {
                sum += b[j--] - '0';
            }
            res += to_string(sum % 2);
            carry = sum / 2;
        }
        if (carry) {
            res += to_string(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main() {

    return 0;
}