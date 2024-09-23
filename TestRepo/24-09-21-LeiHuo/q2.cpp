#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

int main() {
    int N, M, T;
    cin >> N >> M >> T;
    
    class  UF {
    public:
        int total;
        int count;
        vector<int> rank;
        vector<int> parent;
        UF(int N): total(N), count(N), rank(vector<int>(N, 1)), parent(vector<int>(N, 0)) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if (x != parent[x]) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        void merge(int x, int y) {
            int rootX = find(x), rootY = find(y);
            if (rootX == rootY) return;
            if (rank[rootX] < rank[rootY])
                swap(rootX, rootY);
            
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY]) ++rank[rootX];
            --count;
        }

        bool is_connected(int x, int y) {
            return find(x) == find(y);
        }
    };

    UF *uf_ptr = new UF(N);
    unordered_map<int, unordered_map<int, int>> table;
    for (int i = 0; i < M; ++i) {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        table[ai][bi] = 1;
        table[bi][ai] = 1;
        table[ai][ci] = 1;
        table[ci][ai] = 1;
        table[bi][ci] = 1;
        table[ci][bi] = 1;

        uf_ptr->merge(ai, bi);
        uf_ptr->merge(bi, ci);
        uf_ptr->merge(ai, ci);
    } 

    for (int i = 0; i < T; ++i) {
        int ui, vi;
        cin >> ui >> vi;
        if (table.count(ui) && table[ui].count(vi) && table[ui][vi]) {
            cout << 1 << endl;
        } else if (uf_ptr->is_connected(ui, vi)) {
            cout << 2 << endl;
        } else {
            cout << 3 << endl;
        }
    }



    return 0;
}