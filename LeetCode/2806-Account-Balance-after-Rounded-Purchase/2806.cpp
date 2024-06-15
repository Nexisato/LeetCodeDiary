#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int accountBalanceAfterPurchase(int purchaseAmount) { return 100 - (purchaseAmount + 5) / 10 * 10; }
};

int main() { return 0; }