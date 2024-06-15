#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {
		int n = arr.size(), res = 0;
		for (int i = 0, j = 0, minNum = n, maxNum = -1; i < arr.size(); ++i) {
			minNum = min(arr[i], minNum);
			maxNum = max(arr[i], maxNum);
			if (i == maxNum && j == minNum) {
				++res;
				j = i + 1;
				minNum = n;
				maxNum = -1;
			}
		}
		return res;
	}
};
int main() {
	cout << "test" << endl;

	return 0;
}