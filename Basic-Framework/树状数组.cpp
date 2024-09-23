// 线段树在离线场景下不好想，现在开一个树状数组的记录
#include <iostream>
#include <vector>
using namespace std;


class TreeArray {
private:
    vector<int> arr;
    int n;
public:
    TreeArray(int size): n(size), arr(vector<int>(size + 1, 0)) {}

    void update(int idx, int val) {
        while (idx <= n) {
            arr[idx] += val;
            idx += (idx & -idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx >= 1) {
            sum += arr[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    int range_query(int l, int r) {
        return query(r) - query(l - 1);
    }



};


int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = arr.size();

    TreeArray fenwickTree(n);

    // 构建树状数组
    for (int i = 0; i < n; ++i) {
        fenwickTree.update(i + 1, arr[i]);
    }

    // 查询区间和
    int left = 2, right = 6;
    int result = fenwickTree.range_query(left, right);
    cout << "Sum of elements in range [" << left << ", " << right << "] is: " << result << endl;


    return 0;
}