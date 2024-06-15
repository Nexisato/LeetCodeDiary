#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	// 构建next数组，记录【模式串】最长相同前后缀子串长度
	void getNext(vector<int>& next, const string& s) {
		int j = -1;
		next[0] = j;
		for (int i = 1; i < s.length(); ++i) {
			while (j >= 0 && s[i] != s[j + 1])
				j = next[j];
			if (s[i] == s[j + 1])
				++j;
			next[i] = j;
		}
	}

public:
	bool repeatedSubstringPattern(string s) {
		if (s.size() == 0)
			return false;
		vector<int> next(s.size());
		getNext(next, s);
		int len = s.size();

		if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0) {
			return true;
		}
		return false;
	}
};
int main() { return 0; }