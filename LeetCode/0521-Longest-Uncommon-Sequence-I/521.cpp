#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 不要想复杂，只要两个字符串不相等，那么最长的子序列就是两个字符串中最长的那个
class Solution {
public:
	int findLUSlength(string a, string b) {
		if (a == b)
			return -1;
		return max(a.length(), b.length());
	}
};
int main() { return 0; }