#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string reorderSpaces(string text) {
		int n = text.length(), countSpace = n, countWord = 0;
		for (int i = n - 1, j = n - 1, isSwapped = false; i >= 0; --i) {
			if (text[i] != ' ') {
				swap(text[i], text[j--]);
				countWord += !isSwapped;
				isSwapped = true;
				--countSpace;
			} else if (isSwapped) {
				--j;
				isSwapped = false;
			}
		}

		for (int i = 0, j = 0, isSwapped = false, dist = countSpace / max(countWord - 1, 1); i < n; ++i) {
			if (text[i] != ' ') {
				swap(text[i], text[j++]);
				isSwapped = true;
			} else if (isSwapped) {
				j += dist;
				isSwapped = false;
			}
		}
		return text;
	}
};

int main() {
	string text = "  this   is  a sentence ";
	Solution* ss;
	string res = ss->reorderSpaces(text);
	cout << res << endl;

	return 0;
}