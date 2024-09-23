#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


int main() {
    int n;
    cin >> n;
    unordered_map<int, unordered_set<int>> edges;
    for (int i = 0; i < n - 1; ++i) {
        int ui, vi;
        cin >> ui >> vi;
        edges[ui].insert(vi);
        edges[vi].insert(ui);
    }
    int res = 0;

    for (int u = 1; u <= n; ++u) {
        for (auto&& w : edges[u]) {
            for (auto&& v : edges[w]) {
                if (u != v && !edges[u].count(v))
                    ++res;
            }
        }
    }

    res /= 2;
    cout << res << endl;


    return 0;
}