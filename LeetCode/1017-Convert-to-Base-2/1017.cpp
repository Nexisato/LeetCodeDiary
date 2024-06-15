#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 *
 *
 */
class Solution {
public:
	string baseNeg2(int n) {
		if (n == 0 || n == 1)
			return to_string(n);
		string res = "";
		while (n != 0) {
			int r = n & 1; //补码不影响奇偶性
			res += '0' + r;
			n -= r;
			n /= -2;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
int main() {

	int n = 7;
	Solution ss;
	string res = ss.baseNeg2(n);
	cout << res << endl;
	return 0;
}