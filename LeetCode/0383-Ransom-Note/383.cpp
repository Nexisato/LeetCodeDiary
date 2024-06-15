#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> table;
		for (char a : magazine)
			table[a]++;
		for (char b : ransomNote) {
			if (table.find(b) == table.end() || table[b] == 0) //或判断小于 0
				return false;
			table[b]--;
		}
		return true;
	}
};
int main() { return 0; }