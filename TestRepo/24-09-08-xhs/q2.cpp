#include <iostream>
#include <set>
#include <vector>
#include <bitset>

using namespace std;


int f_get_ones(int num) {
    bitset<32> st(num);
    return st.count();
}

// !IMPORTANT: 从右边开始， bitset 下标为 0，
// 从右往左，找到第一个 1，找到第一个 0，中间的1提到最右边，1 提到0 的位置上
unsigned long g_get_next(int num) {
    bitset<33> bst(num);

    // 从右往左找到第一个 1
    int pos1 = -1;
    for (int i = 0; i <= 32; ++i) {
        if (bst[i]) {
            pos1 = i;
            break;
        }
    }
    // 从 pos1 往左找到第一个 0
    int pos0 = -1;
    for (int i = pos1; i <= 32; ++i)
        if (!bst[i]) {
            pos0 = i;
            break;
        }
    int numOnes = pos0 - pos1 - 1;

    for (int i = pos1; i < pos0; ++i)
        bst.set(i, 0);
    bst.set(pos0, 1);

    for (int i = 0; i < numOnes; ++i)
        bst.set(i, 1);

    return bst.to_ulong();

}


int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    set<int> st;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        st.insert(a[i]);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int curL = 0;
        int cur = a[i];
        while (st.count(cur)) {
            ++curL;
            st.erase(cur);
            cur = g_get_next(cur);
        }
        res = max(res, curL);
    }

    cout << res << endl;


    return 0;
}