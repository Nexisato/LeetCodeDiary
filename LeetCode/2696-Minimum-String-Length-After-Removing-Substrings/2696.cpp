/*
 * @Date: 2024-01-10 12:36:32
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2696_Minimum_String_Length_After_Removing_Substrings/2696.cpp
 * @Description:
 */
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

/**
 * 逐个入栈，挨个检查
 */
class Solution {
public:
	int minLength(string s) {
		vector<char> st;
		const int length = s.length();
		int res = length;
		for (int i = 0; i < length; ++i) {
			st.push_back(s[i]);
			if (st.size() >= 2) {
				int n = st.size();
				if (st[n - 1] == 'B' && st[n - 2] == 'A') {
					st.pop_back();
					st.pop_back();
				} else if (st[n - 1] == 'D' && st[n - 2] == 'C') {
					st.pop_back();
					st.pop_back();
				}
			}
		}
		res = st.size();
		return res;
	}
};
int main() { return 0; }