#include <bits/stdc++.h>
using namespace std;
/*
思路:

*/
class Solution {
public:
	int maxLengthBetweenEqualCharacters(string s) {
		int maxL = -1;
		unordered_map<char, int> pos;
		for (int i = 0; i < s.length(); ++i) {
			if (pos.find(s[i]) == pos.end())
				pos[s[i]] = i;
			else
				maxL = max(maxL, i - pos[s[i]] - 1);
		}
		return maxL;
	}
};
int main() { return 0; }