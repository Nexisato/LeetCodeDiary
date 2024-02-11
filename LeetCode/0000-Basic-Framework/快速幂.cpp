/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0000-Basic-Framework/快速幂.cpp
 * @Description: 
 */
#include <iostream>

using namespace std;

// a ^ b, 可以在O(logN)的时间复杂度内求快速幂
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;

}

//模意义下求快速幂
long long binpow_mode(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1)
            res *= (a % m);
        a *= (a % m);
        b >>= 1;
    }
    return res;
}

int main() {
    long long a = 3, b = 13;
    long long res = binpow(a, b);
    cout << res << endl;

    return 0;
}