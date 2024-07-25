#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

// 针对每个字符考虑出现次数之和，毕竟可重
int main() {
	std::string s;
	std::cin >> s;
	int n = s.length();
	std::unordered_map<char, int> table;
	for (auto&& c : s) {
		++table[c];
	}
	const int mod = 1e9 + 7;
	// 考虑针对某个字符 c，包含 c 的子序列的个数是
	// (2^table[c] - 1) * (2 ^ (n - table[c])) % mod
	std::function<int(int, int)> pow = [&](int x, int n) -> int {
		if (n == 0)
			return 1;
		else if (n % 2 == 1) {
			return (long long)x * pow(x, n - 1) % mod;
		} else {
			long long t = pow(x, n / 2);
			return t * t % mod;
		}
	};
	int res = 0;
	for (auto&& [_, cnt] : table) {
		res += (pow(2, cnt) - 1) * pow(2, n - cnt) % mod;
	}
	res %= mod;
	std::cout << res << std::endl;
	return 0;
}