/*
LeetCode 394: Decode String
@Description:
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square
brackets is being repeated exactly k times. Note that k is guaranteed to be a positive
integer.

You may assume that the input string is always valid; No extra white spaces, square
brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that
digits are only for those repeat numbers, k. For example, there won't be input like 3a
or 2[4].

Constraints:
1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
思路：
*/
class Solution {
public:
    string decodeString_fmt(string s) {
        string res;
		vector<char> st;
		const int n = s.length();
		for (int i = 0; i < n; ++i) {
			if (s[i] != ']') {
				st.emplace_back(s[i]);
			} else {
				string token = "";
				while (st.back() != '[') {
					token += st.back();
					st.pop_back();
				}
				st.pop_back();
				string num_str = "";
				while (!st.empty() && isdigit(st.back())) {
					num_str += st.back();
					st.pop_back();
				}
				reverse(num_str.begin(), num_str.end());
				int rep = stoi(num_str);
				reverse(token.begin(), token.end());
				string cur = "";
				for (int j = 0; j < rep; ++j)
					cur += token;
				for (auto c : cur)
					st.emplace_back(c);
			}
		}
        for (auto&& c : st)
            res += c;
               

        return res;
            
    }
	string decodeString(string s) {
		string res = "";
		vector<char> st;
		int n = s.length();
		for (int i = 0; i < n; ++i) {
			if (s[i] == ']') {
				string tmp = "";
				while (st.back() != '[') {
					tmp += st.back();
					st.pop_back();
				}
				st.pop_back();
				string countStr = "";
				while (!st.empty() && st.back() >= 0x30 && st.back() <= 0x39) {
					countStr += st.back();
					st.pop_back();
				}
				reverse(countStr.begin(), countStr.end());
				int count = stoi(countStr);
				reverse(tmp.begin(), tmp.end());
				string copyStr = "";
				for (int j = 0; j < count; ++j)
					copyStr += tmp;
				for (auto c : copyStr)
					st.emplace_back(c);
			} else
				st.emplace_back(s[i]);
		}
		for (auto c : st)
			res += c;
		return res;
	}
};
int main() {
	string s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
	Solution ss;
	string res = ss.decodeString_fmt(s);
	cout << res << endl;
	return 0;
}