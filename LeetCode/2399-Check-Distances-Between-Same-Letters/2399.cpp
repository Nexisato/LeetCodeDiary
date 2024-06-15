#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool checkDistances(string s, vector<int>& distance) {
		unordered_map<char, vector<int>> table;
		for (int i = 0; i < s.length(); ++i) {
			table[s[i]].push_back(i);
		}
		for (int i = 0; i < 26; ++i) {
			char alpha = 'a' + i;
			if (table.count(alpha)) {
				int dis = table[alpha][1] - table[alpha][0] - 1;
				if (dis != distance[i])
					return false;
			}
		}
		return true;
	}
};
int main() { return 0; }