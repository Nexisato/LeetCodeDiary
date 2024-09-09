// 归并排序时统计
#include <iostream>
#include <vector>
using namespace std;

// 需要在归并排序的时候统计逆序对的数量
int merge_sort(vector<int>& arr, int l, int r, vector<int>& tmp) {
    if (l >= r) return 0;
    int mid = l + (r - l) / 2;
    int res = 0;

    res += merge_sort(arr, l, mid, tmp);
    res += merge_sort(arr, mid + 1, r, tmp);
    int i = l, j = mid + 1, pos = l;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            tmp[pos] = arr[i];
            ++i;
        } else {
            res += (mid + 1 - i);  // 从 i 开始到 mid，都比右侧数组大
            tmp[pos] = arr[j];
            ++j;
        }
        ++pos;
    }
    for (int k = i; k <= mid; ++k) {
        tmp[pos] = arr[k];
        ++pos;
    }
    for (int k = j; k <= r; ++k) {
        tmp[pos] = arr[k];
        ++pos;
    }
    copy(tmp.begin() + l, tmp.begin() + r + 1, arr.begin() + l);
    return res;
}


int main() {
    int num;
    vector<int> arr;
    while (cin >> num) {
        arr.push_back(num);
    }

    int n = arr.size();
    vector<int> tmp(n, 0);
    int res = merge_sort(arr, 0, n - 1, tmp);
    cout << res << endl;

    return 0;
}