// 点燃大海！
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;
/**
 * 并查集模板题，再加强一下
 */
class UF {
private:
    int count = 0;
    vector<int> parent;
    int total;

public:
    vector<int> rank;
    UF(int size)
        : parent(vector<int>(size, 0)),
          rank(vector<int>(size, 1)),
          total(size),
          count(size) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        if (rank[rootX] < rank[rootY]) swap(rootX, rootY);
        parent[rootY] = rootX;
        rank[rootX] += rank[rootY];
        --count;
    }

    bool is_connected(int x, int y) { return find(x) == find(y); }

    int get_count() const { return count; }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mp(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> mp[i][j];

    int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    // '.' 是大海，'#' 是陆地
    unordered_set<int> visited;
    UF uf_land(n * m);

    function<void(int, int, int, char, UF&)> dfs = [&](int i, int j, int root, char c, UF& uf) -> void {
        if (i >= n || i < 0 || j < 0 || j >= m || visited.count(i * m + j) || mp[i][j] != c) return;
        int cur_root = uf.find(i * m + j);
        uf.merge(root, cur_root);

        visited.insert(i * m  + j);
        dfs(i + 1, j, root, c, uf); 
        dfs(i - 1, j, root, c, uf); 
        dfs(i, j + 1, root, c, uf); 
        dfs(i, j - 1, root, c, uf); 
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int idx = i * m + j;
            if (!visited.count(idx) && mp[i][j] == '#')
                dfs(i, j, idx, '#', uf_land);
        }
    }

    unordered_set<int> processed;
    function<int(int, int)> dfs2 = [&](int i, int j) -> int {
        if (i >= n || i < 0 || j < 0 || j >= m) return 0;
        int idx = i * m + j;
        if (mp[i][j] == '#') {
            int cur_root = uf_land.find(idx);
            if (processed.count(cur_root)) return 0;
            processed.insert(cur_root);
            return uf_land.rank[cur_root];
        }
        
        if (visited.count(idx)) return 0;
        visited.insert(idx);
        int res = 1;

        res += dfs2(i + 1, j); 
        res += dfs2(i - 1, j); 
        res += dfs2(i, j + 1); 
        res += dfs2(i, j - 1); 
        return res;
    };

    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int idx = i * m + j;
            if (!visited.count(idx) && mp[i][j] == '.') {
                processed.clear();
                res = max(res, dfs2(i, j));
            }
        }
    }
    
    cout << res << endl;



    return 0;
}
