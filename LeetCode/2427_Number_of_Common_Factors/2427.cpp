#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int commonFactors(int a, int b) {
        int maxD = min(a, b);
        int res = 0;
        for (int num = 1; num <= maxD; ++num) {
            if ((a % num == 0) && (b % num == 0)) 
                ++res;
        }
        return res;
    }
};
int main() {

    return 0;
}