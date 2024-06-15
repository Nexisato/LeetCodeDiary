#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int mostFrequentEven(vector<int>& nums) {
		int res = -1, maxCount = 0;
		unordered_map<int, int> table;
		for (const auto& num : nums) {
			if (num % 2 == 0) {
				++table[num];
				if (table[num] > maxCount) {
					maxCount = table[num];
					res = num;
				} else if (table[num] == maxCount) {
					res = min(res, num);
				}
			}
		}
		return res;
	}
};
int main() { return 0; }