/*
Description:
Write a function that reverses a string. The input string is given as an array of
characters char[]. Do not allocate extra space for another array, you must do this by
modifying the input array in-place with O(1) extra memory. You may assume all the
characters consist of printable ascii characters.
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	//思路：双指针
	// notes:
	//循环终止条件
	// slowPtr<s.size()/2，彳亍；
	// fastPtr>=s.size()/2, 不彳亍;
	void reverseString(vector<char>& s) {
		for (int fastPtr = s.size() - 1, slowPtr = 0; slowPtr < s.size() / 2;
		     slowPtr++, fastPtr--)
			swap(s[slowPtr], s[fastPtr]);
	}
	void Print(vector<char>& nums) {
		for (vector<char>::iterator it = nums.begin(); it != nums.end(); it += 1) {
			cout << *(it) << " ";
		}
	}
	int idx = 0;
	void reverse_Recursion(vector<char>& s) { helper(s, 0, s.size() - 1); }
	void helper(vector<char>& s, int start, int end) {
		if (start >= end)
			return;
		swap(s[start], s[end]);
		helper(s, start + 1, end - 1);
	}
};
int main() {
	string init = "hello";
	vector<char> s(init.begin(), init.end());
	Solution ss;
	ss.reverse_Recursion(s);
	// ss.reverseString(s);
	ss.Print(s);

	return 0;
}