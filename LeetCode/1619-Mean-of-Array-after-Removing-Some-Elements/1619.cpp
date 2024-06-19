#include <bits/stdc++.h>
using namespace std;
/*
思路：

*/
class Solution {
public:
	double trimMean(vector<int>& arr) {
		int n = arr.size();
		int count = 0.05 * n;
		sort(arr.begin(), arr.end());
		return (double)accumulate(arr.begin() + count, arr.end() - count, 0) /
		       (n - 2 * count);
	}
};

int main() { return 0; }