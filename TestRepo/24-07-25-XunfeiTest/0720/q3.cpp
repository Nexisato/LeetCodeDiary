#include <algorithm>
#include <cmath>
#include <iostream>

// 三进制分项
int main() {
	int T;
	std::cin >> T;
	for (int _i = 0; _i < T; ++_i) {
		int n;
		std::cin >> n;
		std::vector<int> nums;
		while (n) {
			int mod = n % 3;
			nums.push_back(mod);
			n /= 3;
		}
		std::vector<int> res;
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < 2; ++j) {
				if (nums[i] >> j & 1) {
					int cur = int(pow(3, i)) * int(pow(2, j));
					res.push_back(cur);
				}
			}
		}
		std::cout << res.size() << std::endl;
		std::reverse(res.begin(), res.end());
		for (auto&& x : res) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
