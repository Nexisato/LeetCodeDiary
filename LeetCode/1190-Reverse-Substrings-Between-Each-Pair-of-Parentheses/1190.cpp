/*
LeetCode 1190: Reverse Substrings Between Each Pair of Parentheses
@Description:
You are given a string s that consists of lower case English letters and brackets. 

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

 
Constraints:
0 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It's guaranteed that all parentheses are balanced.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：

*/
class Solution {
public:
	string reverseParentheses(string s) {
		int n = s.length();
		vector<int> st;
		string res = "";
		int l = 0, r = 0;
		for (int i = 0; i < n; ++i) {
			st.push_back(i);
			if (s[st.back()] == ')') {
				int r = i, l = i;
				while (s[st.back()] != '(')
					st.pop_back();
				l = st.back() + 1;
				st.pop_back();
				reverse(s.begin() + l, s.begin() + r);
			}
		}
		for (char c : s)
			if (c != '(' && c != ')')
				res += c;
		return res;
	}
};