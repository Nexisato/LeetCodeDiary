#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minOperations(vector<string>& logs) {
		int n = logs.size(), res = 0;
		for (int i = 0; i < n; ++i) {
			if (logs[i] == "./")
				continue;
			else if (logs[i] == "../")
				res = max(0, res - 1);
			else
				++res;
		}
		return res;
	}
};
int main() { return 0; }