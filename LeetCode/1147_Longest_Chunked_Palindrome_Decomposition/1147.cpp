#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * 贪心证明：从左右两边 len = 1 开始不断 judge
 * Rolling Hash：滚动哈希，
 * 
 */
class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.length();
        int res = 0;

        auto judge = [](const string& text, int l1, int l2, int len) -> bool {
            while (len--) {
                if (text[l1] != text[l2])
                    return false;
                ++l1;
                ++l2;
            }
            return true;
        };

        // 左子串左边，右子串右边
        int l = 0, r = n - 1;
        while (l <= r) {
            int len = 1;
            while (l + len - 1 < r - len + 1) {
                if (judge(text, l, r - len + 1, len)) {
                    res += 2;
                    break;
                }
                ++len;
            }
            if (l + len - 1 >= r - len + 1) ++res;
            l += len;
            r -= len;
        }

        return res;
    }
private:
    using ll = long long;
    vector<ll> pre1, pre2;
    vector<ll> pow1, pow2;
    static constexpr int MOD1 = 1000000007;
    static constexpr int MOD2 = 1000000009;
    int Base1, Base2;

    void init(string& s) {
        mt19937 gen{random_device{}()};
        Base1 = uniform_int_distribution<int>(1e6, 1e7)(gen);
        Base2 = uniform_int_distribution<int>(1e6, 1e7)(gen);
        while (Base2 == Base1) {
            Base2 = uniform_int_distribution<int>(1e6, 1e7)(gen);
        }
        int n = s.size();
        pow1.resize(n);
        pow2.resize(n);
        pre1.resize(n + 1);
        pre2.resize(n + 1);
        pow1[0] = pow2[0] = 1;
        pre1[1] = pre2[1] = s[0];
        for (int i = 1; i < n; ++i) {
            pow1[i] = (pow1[i - 1] * Base1) % MOD1;
            pow2[i] = (pow2[i - 1] * Base2) % MOD2;
            pre1[i + 1] = (pre1[i] * Base1 + s[i]) % MOD1;
            pre2[i + 1] = (pre2[i] * Base2 + s[i]) % MOD2;
        }
    }

    pair<int, int> getHash(int l, int r) {
        return {(pre1[r + 1] - ((pre1[l] * pow1[r + 1 - l]) % MOD1) + MOD1) % MOD1, (pre2[r + 1] - ((pre2[l] * pow2[r + 1 - l]) % MOD2) + MOD2) % MOD2};
    }


    int longestDecomposition_rollinghash(string text) {
        int n = text.length();
        int res = 0;
        // 主要区别在于 judge 函数转化为哈希计算
        init(text);
        
        int l = 0, r = n - 1;
        while (l <= r) {
            int len = 1;
            while (l + len - 1 < r - len + 1) {
                if (getHash(l, l + len - 1) == getHash(r - len + 1, r)) {
                    res += 2;
                    break;
                }
                ++len;
            }
            if (l + len - 1 >= r - len + 1) ++res;
            l += len;
            r -= len;
        }

        return res;
    }
};
int main() {


    return 0;
}