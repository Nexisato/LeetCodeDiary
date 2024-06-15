#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
		int n = energy.size();
		int res = 0;
		int curEnergy = initialEnergy, curExp = initialExperience;
		for (int i = 0; i < n; i++) {
			if (curEnergy <= energy[i]) {
				res += energy[i] - curEnergy + 1;
				curEnergy = energy[i] + 1;
			}
			if (curExp <= experience[i]) {
				res += experience[i] - curExp + 1;
				curExp = experience[i] + 1;
			}
			curEnergy -= energy[i];
			curExp += experience[i];
		}
		return res;
		/* 更优雅的解法
		int energySum = accumulate(energy.begin(), energy().end(), 0);
		int res = max(0, s - initialEnergy + 1);
		for (int x : experience) {
		    if (initialExperience <= x) {
		        res += x - initalExperience + 1;
		        initalExperience =  x + 1;
		    }
		    initalExperience += x;
		}
		return res;
		*/
	}
};
int main() { return 0; }