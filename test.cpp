#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	vector<int> nums(11, 0);
	int n = 10;
	int num = 11;
	while (n) {
		nums[n] = num;
		++num;
		--n;
	}
	for (const auto& i : nums)
		cout << i << " ";
	cout << endl;

	return 0;
}