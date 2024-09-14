#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

// Prim 最小生成树，约等于 Dijkstra
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> locations;
    vector<vector<long long>> dists(n, vector<long long>(n, INT32_MAX));
    for (int i = 0; i < n; ++i)
        dists[i][i] = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        locations.push_back({x, y});
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int xi = locations[i].first, yi = locations[i].second;
            int xj = locations[j].first, yj = locations[j].second;
            long long cur_dis = abs(xi - xj) + abs(yi - yj);
            dists[i][j] = cur_dis;
            dists[j][i] = cur_dis;
        }
    }
    
    vector<bool> visisted(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 0});
    int min_cost = 0;
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (visisted[u])
            continue;
        min_cost = d;
        visisted[u] = true;
        for (int i = 0; i < n; ++i) {
            if (!visisted[i] && dists[u][i] != INT32_MAX) {
                q.push({dists[u][i], i});
            }
        }
    }

    int res = (int)(min_cost + 1) / 2;
    cout << res << endl;

    

    return 0;
}