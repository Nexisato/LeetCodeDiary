

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minSpeedOnTime(vector<int>& dist, double hour) {
		int n = dist.size();
		if ((double)(n - 1) >= hour)
			return -1;
		double rem = hour - (n - 1);
		int res = ceil((double)dist[n - 1] / rem);
		return (res > 1e+7) ? (1e+7) : res;
	}
};
int main() {
	Solution ss;
	vector<int> dist{1, 2, 100000};
	double hour = 2.01;
	int res = ss.minSpeedOnTime(dist, hour);
	cout << res << endl;
	return 0;
}