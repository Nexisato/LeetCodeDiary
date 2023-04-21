#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int gcd(int a, int b) {
        int n = max(a, b), m = min(a, b);
        if (m == 0)
            return n;
        return gcd(m, n % m);
    }
public:
    int smallestEvenMultiple(int n) {
        return (2 * n) / gcd(2, n);
    }
};
int main() {


    return 0;
}