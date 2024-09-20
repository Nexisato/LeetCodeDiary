#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// k 次变换
// 每次变换最多 l 个
int main() {
    int n, k, l;
    cin >> n >> k >> l;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());
    




    return 0;
}
