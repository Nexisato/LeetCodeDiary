#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i)  {
        cin >> arr[i];

    }

    int res = INT32_MAX;

    vector<int> next(n, -1);
    vector<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[st.back()] > arr[i]) {
            next[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }










    cout << res << endl;
    return 0;
}
