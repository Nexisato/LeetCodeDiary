#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool checkOnesSegment(string s) {
		int n = s.length();
		int i = 0, cnt = 0;
		while (i < n && cnt <= 1) {
			while (i < n && s[i] == '0')
				++i;
			if (i < n) {
				while (i < n && s[i] == '1')
					++i;
				++cnt;
			}
		}
		return cnt <= 1;
	}
};
int main() { return 0; }