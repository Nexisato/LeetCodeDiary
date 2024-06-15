#include <bits/stdc++.h>
using namespace std;

/*
思路：
number 必须为 {0,1,8, 2,5,6,9} 中的数字
且至少存在一个在 {2, 5, 6, 9} 中
下午看数位DP
*/
class Solution {
public:
	int rotatedDigits(int n) {
		int res = 0;
		unordered_set<int> rotateNum({0, 1, 8, 2, 5, 6, 9}), rotateChanged({2, 5, 6, 9});
		for (int num = 1; num <= n; ++num) {
			bool isChanged = false;
			int _num = num, _digit;
			while (_num != 0) {
				_digit = _num % 10;
				if (rotateNum.count(_digit) == 0)
					break;
				if (rotateChanged.count(_digit))
					isChanged = true;
				_num /= 10;
			}
			res += isChanged && !_num;
		}

		return res;
	}
};
int main() {
	Solution* ss;
	int num = 0;
	cout << ss->rotatedDigits(857) << endl;
	return 0;
}