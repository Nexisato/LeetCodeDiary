#include <iostream>
#include <string>
using namespace std;

// 00 在前缀补1，10 后移 1
// 字符串最多只有一个 0
class Solution {
public:
	string maximumBinaryString(string binary) {
		const int n = binary.length();
		int j = 0;

		for (int i = 0; i < n; ++i) {
			if (binary[i] == '0') {
				while (j <= i || (j < n && binary[j] == '1'))
					++j;
				if (j < n) {
					binary[j] = '1';
					binary[i] = '1';
					binary[i + 1] = '0';
				}
			}
		}

		return binary;
	}
};
int main() { return 0; }