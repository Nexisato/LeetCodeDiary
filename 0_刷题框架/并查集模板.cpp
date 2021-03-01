#include <bits/stdc++.h>
using namespace std;
const int MAXN = 999;

// 1. 初始化 & 查询
int fa[MAXN];
inline void init(int n) {
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
}

int find(int x) {
    if (fa[x] == x)
        return x;
    else 
        return find(fa[x]);
}

inline void merge(int i, int j) {
    fa[find(i)] = find(j);
}

// 2. 路径压缩
//将沿途的每个节点的父节点都设为根节点
int find(int x) {
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

// 3. 按秩压缩 （可能带来额外的空间复杂度）

int rank[MAXN] = {0};
inline void init(int n) {
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        rank[i] = 1;
    }
}
inline void merge(int i, int j) {
    int x = find(i), y = find(j);
    if (rank[x] <= rank [y]) 
        fa[x] = y;
    else
        fa[y] = x;
    if (rank[x] == rank[y] && x != y)
        rank[y]++;
}

//查询两点是否同根
bool isSame(int i, int j) {
    return find(i) == find(j);
}

//常规
class Djset {
private:
    vector<int> parent;  // 记录节点的根
    vector<int> rank;  // 记录根节点的深度（用于优化）
    int count;
public:
    Djset(int n): parent(vector<int>(n)), rank(vector<int>(n)), count(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        // 压缩方式：直接指向根节点
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) 
                swap(rootx, rooty);
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            count--;
        }
    }

    int get_count() {
        return count;
    }

    bool isMerged(int x, int y) {
        return find(x) == find(y);
    }
};

//需要计算连通图的
class Djset {
public:
    unordered_map<int, int> parent, rank;
    int count;
    Djset(int n): count(0){}
    
    int find(int x) {
        //未加入并查集
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            count++;
        }
        //路径压缩，父节点作为根节点
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    inline void merge(int x, int y) {// y->x; 低秩并到高秩
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty])
                swap(rootx, rooty);
            parent[rooty] = rootx;
            if (rootx == rooty) 
                rank[rootx] += 1;
            count--;
        }

    }
    int get_count() {
        return count;
    }
};