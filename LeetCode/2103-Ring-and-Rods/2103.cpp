#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief
 * 红: 001
 * 绿: 010
 * 蓝: 100
 */
class Solution {
public:
	int countPoints(string rings) {
		int res = 0;
		vector<int> rods(10, 0);
		for (int i = 0; i < rings.length(); i += 2) {
			char color = rings[i];
			int idx = rings[i + 1] - '0';
			if (color == 'R') {
				rods[idx] |= 1;
			} else if (color == 'G') {
				rods[idx] |= 2;
			} else {
				rods[idx] |= 4;
			}
		}
		for (int i = 0; i < 10; ++i)
			res += (rods[i] == 7) ? 1 : 0;

		return res;
	}
};

int main() {
	Solution* sol = new Solution();
	string rings = "B0R0G0R9R0B0G0";
	cout << sol->countPoints(rings) << endl;

	return 0;
}