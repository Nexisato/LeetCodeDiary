#include <iostream>
#include <string>
#include <vector>
using namespace std;
/**
 * 思路：
 */
class Solution {
public:
	bool isAcronym(vector<string>& words, string s) {
		int i = 0, j = 0;
		while (i < words.size() && j < s.size()) {
			if (words[i][0] == s[j]) {
				i++;
				j++;
			} else {
				return false;
			}
		}
		return j == s.length() && i == words.size();
	}
};
int main() { return 0; }