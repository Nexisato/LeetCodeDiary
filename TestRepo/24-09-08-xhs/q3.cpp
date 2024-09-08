/*
目前没有这一套题目流出，占个位置先
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;



int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int _i = 0; _i < q; ++_i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        while (l < r && a[l] == a[r]){
            --r;
        }
        int res = r - l + 1;
        if (res == 1) res = 0;
        cout << res << endl;


    }



    return 0;
}