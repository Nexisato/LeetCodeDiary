#include <bits/stdc++.h>
using namespace std;
/*
直接模拟即可
*/
class Solution {
public:
	int minOperationsMaxProfit(vector<int>& customers, int boardingCost,
	                           int runningCost) {
		int n = customers.size(), res = -1;
		if (boardingCost * 4 - runningCost < 0)
			return -1;
		auto calcProfit = [&boardingCost, &runningCost](int customerNum,
		                                                int rotateNum) -> int {
			return customerNum * boardingCost - runningCost;
		};
		int sum = accumulate(customers.begin(), customers.end(), 0), maxProfit = 0,
		    customerPool = 0, sumProfit = 0;
		int index = 0, round = 1;
		while (index < n || sum != 0) {
			if (index < n)
				customerPool += customers[index];
			if (customerPool > 4) {
				sumProfit += calcProfit(4, round);
				customerPool -= 4;
				sum -= 4;
			} else {
				sumProfit += calcProfit(customerPool, round);
				sum -= customerPool;
				customerPool = 0;
			}
			if (sumProfit > maxProfit) {
				maxProfit = sumProfit;
				res = round;
			}
			round++;
			index++;
		}

		return res;
	}
};
int main() { return 0; }