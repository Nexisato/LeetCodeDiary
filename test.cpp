#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <ranges>

int main() {
	std::vector<int> nums(11, 0);
	int n = 10;
	int num = 11;
	while (n) {
		nums[n] = num;
		++num;
		--n;
	}

	std::ranges::sort(nums);
	for (int i = 0; i < 11; ++i)
		std::cout << nums[i] << "\t";
	std::cout << std::endl;

	return 0;
}