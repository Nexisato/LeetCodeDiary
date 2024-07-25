#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

// 签到题
int main() {
	int n, k;
	std::cin >> n >> k;
	std::unordered_map<int, int> table;
	for (int _i = 0; _i < n; ++_i) {
		int x;
		std::cin >> x;
		++table[x];
	}
	std::vector<int> res;
	for (auto&& [num, count] : table) {
		if (count <= k)
			res.push_back(num);
	}
	if (res.empty()) {
		std::cout << -1 << std::endl;
	} else {
		std::cout << *std::min_element(res.begin(), res.end()) << std::endl;
	}
	return 0;
}