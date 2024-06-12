#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        return 100 - (purchaseAmount + 5) / 10  * 10;
    }
};

int main() {


    return 0;
}