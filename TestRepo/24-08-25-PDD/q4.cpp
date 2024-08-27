#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;



int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        s.push_back(c);
    }

    function<void(int, int)> reverse = [&](int l, int r) -> void {
        if (l >= r) return;
        while (l < r) {
           swap(s[l], s[r]);
           ++l;
           --r; 
        }
    };


    vector<vector<int>> dp(n, vector<int>(2, 0));

    for (int i = 0; i < n - 1; ) {
        if (s[i] == '0' && s[i + 1] == '0') {
            ++i;
            continue;
        }
        else if (s[i] == '1' && s[i + 1] == '1') {
            ++i;
            continue;
        }
        else {
            dp[i][i + 1] = 2;
        }
    }









    return 0;
}
