#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> frequencySort(vector<int>& nums) {
		unordered_map<int, int> table;
		for (const auto& num : nums)
			++table[num];
		sort(nums.begin(), nums.end(), [&table](int a, int b) {
			if (table[a] != table[b])
				return table[a] < table[b];
			return a > b;
		});
		return nums;
	}
};
int main() { return 0; }