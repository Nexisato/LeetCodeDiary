#include <bits/stdc++.h>
using namespace std;

/*
思路：
比较 %2 余 1 和 %2 余 0 的最小值
*/
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int modOne = 0, modZero = 0;
        for (auto &pos : position) {
            if (pos % 2 == 1)
                ++modOne;
            else
                ++modZero;
        }
        return min(modZero, modOne);
    }
};

int main() {

    std::cout << "Hello World" << std::endl;

    return 0;
}