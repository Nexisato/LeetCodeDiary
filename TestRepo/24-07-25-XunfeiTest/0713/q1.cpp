#include <iostream>
#include <string>
#include <vector>


// 签到题
int main() {
	int T;
	std::cin >> T;
	for (int __i = 0; __i < T; ++__i) {
		int n;
		std::cin >> n;
		std::string s;
		std::cin >> s;
		std::vector<int> res(n, -1);
		int lastZeroIdx = -1, lastOneIdx = -1;
		for (int i = 0; i < n; ++i) {
			char c = s[i];
			if (c == '0') {
				res[i] = lastOneIdx;
				lastZeroIdx = i + 1;
			} else {
				res[i] = lastZeroIdx;
				lastOneIdx = i + 1;
			}
		}
		for (int i = 0; i < n; ++i) {
			std::cout << res[i] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}