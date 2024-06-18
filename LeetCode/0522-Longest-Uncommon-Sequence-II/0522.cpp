#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
	// s-substr, t-fullstr
	bool is_substr(const string& s, const string& t) {
		int idx = 0;
		for (auto&& c : t) {
			if (s[idx] == c && ++idx == s.length())
				return true;
		}
		return false;
	}

public:
	int findLUSlength(vector<string>& strs) {
		int res = -1;
		const int n = strs.size();
		for (int i = 0; i < n; ++i) {
			if ((int)strs[i].length() <= res) {
				continue;
			}
			bool is_unique = true;
			for (int j = 0; j < n; ++j) {
				if (j != i && is_substr(strs[i], strs[j])) {
					is_unique = false;
					break;
				}
			}
			if (is_unique)
				res = strs[i].length();
		}
		return res;
	}
};
int main() { return 0; }