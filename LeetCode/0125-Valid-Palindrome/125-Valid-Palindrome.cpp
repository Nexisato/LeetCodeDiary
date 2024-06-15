/*
Description:
Given a string, determine if it is a palindrome,
considering only alphanumeric characters and ignoring cases.
Note: For the purpose of this problem, we define empty string as valid palindrome.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	//思路：大坑题！双指针遍历字符串中的字母，注意0P这个坑；字母和数字字符都算回文串！
	bool isPalindrome(string s) {
		int length = 0;
		char store[s.size()];
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z' || '0' <= s[i] && s[i] <= '9')
				store[length++] = s[i];
			else if (s[i] <= 'Z' && s[i] >= 'A')
				store[length++] = s[i] + 32;
		}

		for (int ptr1 = 0, ptr2 = length - 1; ptr1 < ptr2; ptr1++, ptr2--)
			if (store[ptr1] != store[ptr2])
				return false;

		return true;
	}
	bool isPalindrome2(string s) {
		string tmp;
		for (auto c : s) {
			if (islower(c) || isdigit(c))
				tmp += c;
			else if (isupper(c))
				tmp += (c + 32);
		}
		int i = 0, j = tmp.size() - 1;
		while (i < j) {
			if (tmp[i] != tmp[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
};

int main() {
	string s1 = "0p";
	Solution ss;
	cout << ss.isPalindrome2(s1) << endl;
	return 0;
}