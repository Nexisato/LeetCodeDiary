#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * 思路：
 *
 */
class Solution {
public:
	int minNumberOfFrogs(string croakOfFrogs) {
		if (croakOfFrogs.size() % 5 != 0)
			return -1;
		unordered_map<char, int> table{{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
		int res = 0, frogNum = 0;
		vector<int> cnt(5, 0);
		for (char a : croakOfFrogs) {
			int idx = table[a];
			++cnt[idx];
			if (idx == 0) {
				res = max(res, ++frogNum);
			} else {
				if (--cnt[idx - 1] < 0) //此前未发出完整的croak
					return -1;
				if (idx == 4)
					--frogNum;
			}
		}
		if (frogNum > 0)
			return -1;
		return res;
	}
};
int main() { return 0; }