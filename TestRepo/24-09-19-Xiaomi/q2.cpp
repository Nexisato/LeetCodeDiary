#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n, 0), b(n, 0);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];

        function<bool(bool)> judge = [&](bool is_increase) -> bool {
            bool ret = true;
            vector<int> tmp(n, 0);
            if (is_increase) {
                tmp[0] = min(a[0], b[0]);
            } else {
                tmp[0] = max(a[0], b[0]);
            }
            for (int i = 1; i < n; ++i) {
                int ai = a[i], bi = b[i];
                int min_e = min(ai, bi);
                int max_e = max(ai, bi);
                if (is_increase) {
                    if (max_e < tmp[i - 1]) {
                        ret = false;
                        break;
                    }
                    if (min_e >= tmp[i - 1]) {
                        tmp[i] = min_e;
                    } else {
                        tmp[i] = max_e;
                    }

                } else {
                    if (min_e > tmp[i - 1]) {
                        ret = false;
                        break;
                    }
                    if (max_e <= tmp[i - 1]) {
                        tmp[i] = max_e;
                    } else {
                        tmp[i] = min_e;
                    }
                }

            }


            return ret;
        };
        

        bool res = judge(true) || judge(false);
        if (res) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}