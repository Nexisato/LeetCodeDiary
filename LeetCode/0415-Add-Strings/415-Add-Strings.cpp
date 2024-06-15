/*
LeetCode: 415 Add Strings
Description:
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:
The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
#include <bits/stdc++.h>
using namespace std;

/*
思路：模拟竖式相加
更简洁的写法
*/
class Solution_simple {
public:
	string addStrings(string num1, string num2) {
		int i = num1.length() - 1, j = num2.length() - 1, add = 0;
		string ans = "";
		while (i >= 0 || j >= 0 || add != 0) {
			int x = (i >= 0) ? (num1[i] - '0') : 0;
			int y = (j >= 0) ? (num2[j] - '0') : 0;
			int result = x + y + add;
			ans.push_back('0' + result % 10);
			add = result / 10;
			i -= 1;
			j -= 1;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
class Solution {
public:
	string addStrings(string num1, string num2) {
		int m = num1.length(), n = num2.length();
		string res = "";
		int i = m - 1, j = n - 1;
		/*
		int c = 0;
		while (i >= 0 && j >= 0) {
		    int tmp = num1[i] - '0' + num2[j] - '0' + c;
		    j--;
		    c = 0;
		    if (tmp >= 10) {
		        tmp -= 10;
		        c = 1;
		    }
		    res += tmp + 48;
		    i--;
		}
		while (j >= 0) {
		    int tmp = num2[j] - '0' + c;
		    c = 0;
		    if (tmp >= 10) {
		        tmp -= 10;
		        c = 1;
		    }
		    res += tmp + 48;
		    j--;
		}
		while (i >= 0) {
		    int tmp = num1[i] - '0' + c;
		    c = 0;
		    if (tmp >= 10) {
		        tmp -= 10;
		        c = 1;
		    }
		    res += tmp + 48;
		    i--;
		}
		if (c) res += c + 48;
		*/
		reverse(res.begin(), res.end());
		return res;
	}
};
int main() {
	string s1 = "1";
	string s2 = "999";
	Solution ss;
	cout << ss.addStrings(s1, s2) << endl;

	return 0;
}