/*
LeetCode 1734: Decoded XORed Permutation
@Description:
There is an integer array perm that is a permutation of the first n positive integers, where n is always odd.

It was encoded into another integer array encoded of length n - 1, such that encoded[i] = perm[i] XOR perm[i + 1]. 
For example, if perm = [1,3,2], then encoded = [2,1].

Given the encoded array, return the original array perm. It is guaranteed that the answer exists and is unique.

Constraints:
3 <= n < 10^5
n is odd.
encoded.length == n - 1
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
perm[0] = total ^ encoded[1] ^ encoded[3] ...
*/
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        vector<int> perm(n, 0);

        auto total = [](int n){
            int res = 0;
            for (int i = 1; i <= n; ++i)
                res ^= i;
            return res;
        };
        int x = total(n);
        perm[0] = x;
        for (int i = 1; i < n - 1; i += 2) 
            perm[0] ^= encoded[i];
        
        for (int i = 1; i < n; ++i)
            perm[i]  = encoded[i - 1] ^ perm[i - 1];

        return perm;
    }
};
int main() {

    int a = 3, b = 1;
    int c = a ^ b;
    cout << c << endl;
    return 0;
}