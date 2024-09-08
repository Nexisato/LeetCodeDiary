#include <iostream>
using namespace std;

int get_count(int num) {
    int res = 0;
    while (num > 0) {
        int cur = num % 10;
        if (cur == 4 || cur == 6)
            ++res;
        num /= 10;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    int max_count = 0, max_num = 0;
    for (int num = n; num <= m; ++num) {
        int cur = get_count(num);
        if (cur > max_count) {
            max_count = cur;
            max_num = num;
        }
        else if (cur == max_count && num > max_num) {
            max_num = num;
        }
    }
    cout << max_num << endl;

    return 0;
}
