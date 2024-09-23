#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string S;
    cin >> S;

    int res = 0;
    for (int i = 1; i < n; ++i) {
        if (S[i] == S[i - 1]) {
            if (S[i] >= 'a' && S[i] < 'z') {
                ++S[i];
                ++res;
            } else if (S[i] == 'z') {
                S[i] = 'a';
                ++res;
            }
        }
    }
    cout << res << endl;



    return 0;
}