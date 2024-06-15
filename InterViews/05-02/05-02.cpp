#include <bits/stdc++.h>
using namespace std;

/*
直接模拟即可
*/
class Solution {
public:
	string printBin(double num) {
		const string ERR = "ERROR";
		double base = 0.5;
		int count = 0;
		string res = "0.";
		while (num > 0 && count < 30) {
			if (num - base >= 0) {
				num -= base;
				res += "1";
			} else
				res += "0";
			base *= 0.5;
			++count;
		}
		if (num != 0)
			return ERR;
		return res;
	}
};
int main() {
	double num = 0.1;
	Solution ss;
	cout << ss.printBin(num) << endl;

	return 0;
}