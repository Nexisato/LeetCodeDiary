#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        total += arr[i];
    }
    long long l_sum = 0;
    long long res = INT32_MAX;
    for (int i = 0; i < n - 1; ++i) {
        l_sum += arr[i];
        long long r_sum = total - l_sum;
        long long cur = l_sum * r_sum; 
        res = min(res, cur);
    }

 
    
    cout << res << endl;



    return 0;
}