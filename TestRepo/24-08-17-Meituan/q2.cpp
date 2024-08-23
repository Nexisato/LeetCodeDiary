#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



// 模拟，数组都靠近平均值即可
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    long long res = 0;
    long long eval = sum / n;
    if (sum % n == 0) {
        for (int i = 0; i < n; ++i)
            if (arr[i] < eval)
                res += eval - arr[i];
    } else {
        int cnt_more = sum - eval * n;  // cnt_more 个 eval + 1
        int cnt_less = n - cnt_more;    // cnt_less 个 eval
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; ++i) {
            if (i < cnt_less && arr[i] < eval)
                res += eval - arr[i];
            else if (i >= cnt_less && arr[i] < eval + 1)
                res += (eval + 1 - arr[i]);
        }
    
    }

    cout << res << endl;



    return 0;
}