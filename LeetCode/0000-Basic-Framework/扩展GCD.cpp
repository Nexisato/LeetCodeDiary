/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0000-Basic-Framework/扩展GCD.cpp
 * @Description:
 */
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// 1. GCD：递归和非递归
int gcd(int a, int b) {
    int m = max(a, b), n = min(a, b);
    if (n == 0)
        return m;
    return gcd(n, m % n);
}

int gcd_iter(int a, int b) {
    int m = max(a, b), n = min(a, b);
    if (n == 0)
        return m;
    int z = 0;
    while (m % n) {
        z = n;
        n = m % n;
        m = z;
    }
    return n;
}

// 2. extend gcd：求解 ax + by = gcd(a, b) 的一组可行解，基于 ax1 + by1 = ay2 +
// b(x2 - int(a/b)y2) 的推论
void exGcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    // exGcd(b, a % b, x, y);
    // int tmp = x;
    // x = y;
    // y = tmp - int(a / b) * y;
    exGcd(b, a % b, y, x);
    y -= int(a / b) * x;
}

// 3. exGcd 求a mod m 的逆元 aa^{-1} === 1 mod (m)
int invElem(int a, int m) {
    int x, y;
    exGcd(a, m, x, y);
    return (x % m + m) % m;
}

/**
 * @brief 中国剩余定理 (Chinese Remainder Theorem, CRT)
 * 求一元线性同余方程组
 * x mod n1 = a1, x mod n2 = a2, ..., x mod nk = ak; n1,n2,...,nk 两两互质
 *
 * @return x
 */

using ll = long long;
ll CRT(int k, ll *a, ll *r) {
    ll n = 1, res = 0;
    // 1. 所有模乘
    for (int i = 0; i < k; ++i)
        n *= r[i];
    // 2. 对每个方程
    for (int i = 0; i < k; ++i) {
        ll mi = n / r[i]; // 求 mi mod ni 意义下的逆元

        int mi_inv, y;
        exGcd(mi, r[i], mi_inv, y);

        res = (res + a[i] * mi * mi_inv % n) % n;
    }
    return (res % n + n) % n;
}

int main() {
    int a = 252, b = 198;
    cout << gcd(a, b) << endl;
    cout << gcd_iter(a, b) << endl;

    // int x, y;
    // exGcd(a, b, x, y);
    // cout << x << " " << y << endl;
    // int m = 7, n = 31;
    // cout << m % n << endl;
    // int m_inv = invElem(m, n);
    // cout << m_inv % n << endl;
    // cout << (m * m_inv) % n << endl;
    // ll a[3] = {2, 3, 2};
    // ll r[3] = {3, 5, 7};
    // int k = 3;
    // ll res = CRT(k, a, r);
    // cout << res << endl;

    return 0;
}