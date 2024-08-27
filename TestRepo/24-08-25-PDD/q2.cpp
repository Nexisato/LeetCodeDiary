#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        int odd_count = 0, even_count = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (arr[i] % 2 == 1)
                ++odd_count;
            else
                ++even_count;
        }
        if (even_count == 0) {
            cout << 0 << endl;
        }
        else if (odd_count == 0) {
            long long min_ops = INT32_MAX;
            for (int i = 0; i < n; ++i) {
                int num = arr[i];
                long long cur_ops = 0;  // WCNM!
                while (num > 1 && (num % 2 == 0)) {
                    ++cur_ops;
                    num >>= 1;
                }
                if (cur_ops > 0)
                    min_ops = min(min_ops, cur_ops);
            }
            long long res = min_ops + (n - 1);
            cout << res << endl;

        } else {
            cout << even_count << endl;
        }
    }


    return 0;
}
