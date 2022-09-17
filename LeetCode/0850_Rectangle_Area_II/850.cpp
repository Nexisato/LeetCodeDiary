#include <bits/stdc++.h>
using namespace std;

/*
思路：

*/
class Node {
public:
    int l, r, cnt, length;
};

class SegmentTree {
public:
    vector<Node*> tree;
    vector<int> nums;

    explicit SegmentTree(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size() - 1;
        tree.resize(n << 2);
        for (int i = 0; i < tree.size(); ++i) tree[i] = new Node();
        build(1, 0, n - 1);
    }

    void build(int u, int l, int r) {
        tree[u]->l = l;
        tree[u]->r = r;
        if (l != r) {
            int mid = l + (r - l) >> 1;
            build(u << 1, l, mid);
            build(u << 1 | 1, mid + 1, r);
        }
    }

    void modify(int u, int l, int r, int k) {
        if (tree[u]->l >= l && tree[u]->r <= r)
            tree[u]->cnt += k;
        else {
            int mid = tree[u]->l + (tree[u]->r - tree[u]->l) >> 1;
            if (l <= mid) modify(u << 1, l, r, k);
            if (r > mid) modify(u << 1 | 1, l, r, k);
        }
        pushup(u);
    }

    int query() {
        return tree[1]->length;
    }

    void pushup(int u) {
        if (tree[u]->cnt)
            tree[u]->length = nums[tree[u]->r + 1] - nums[tree[u]->l];
        else if (tree[u]->l == tree[u]->r)
            tree[u]->length = 0;
        else
            tree[u]->length = tree[u << 1]->length + tree[u << 1 | 1]->length;
    }
};

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int modulo = 1e9 + 7;
        long long res = 0;
        int n = rectangles.size();

        vector<vector<int>> segs(n << 1);
        int i = 0;
        set<int> ts;
        for (const auto& rec : rectangles) {
            int x1 = rec[0], y1 = rec[1], x2 = rec[2], y2 = rec[3];
            segs[i++] = {x1, y1, y2, 1};
            segs[i++] = {x2, y1, y2, -1};
            ts.insert(y1);
            ts.insert(y2);
        }
        sort(segs.begin(), segs.end());
        unordered_map<int, int> m;
        i = 0;
        for (int v : ts) 
            m[v] = i++;
        vector<int> nums(ts.begin(), ts.end());
        SegmentTree* tree = new SegmentTree(nums);
        for (int i = 0; i < segs.size(); ++i) {
            auto e = segs[i];
            int x = e[0], y1 = e[1], y2 = e[2], k = e[3];
            if (i > 0) 
                res += (long long) tree->query() * (x - segs[i - 1][0]);
            tree->modify(1, m[y1], m[y2] - 1, k);
        }

        res %= modulo;
        return (int)res;
    }
};
/*
class Node {
public:
    int l, r, cnt, length;
};

class SegmentTree {
public:
    vector<Node*> tr;
    vector<int> nums;

    SegmentTree(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size() - 1;
        tr.resize(n << 2);
        for (int i = 0; i < tr.size(); ++i) tr[i] = new Node();
        build(1, 0, n - 1);
    }

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l != r) {
            int mid = (l + r) >> 1;
            build(u << 1, l, mid);
            build(u << 1 | 1, mid + 1, r);
        }
    }

    void modify(int u, int l, int r, int k) {
        if (tr[u]->l >= l && tr[u]->r <= r)
            tr[u]->cnt += k;
        else {
            int mid = (tr[u]->l + tr[u]->r) >> 1;
            if (l <= mid) modify(u << 1, l, r, k);
            if (r > mid) modify(u << 1 | 1, l, r, k);
        }
        pushup(u);
    }

    int query() {
        return tr[1]->length;
    }

    void pushup(int u) {
        if (tr[u]->cnt)
            tr[u]->length = nums[tr[u]->r + 1] - nums[tr[u]->l];
        else if (tr[u]->l == tr[u]->r)
            tr[u]->length = 0;
        else
            tr[u]->length = tr[u << 1]->length + tr[u << 1 | 1]->length;
    }
};

class Solution {
public:
    const int mod = 1e9 + 7;

    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        vector<vector<int>> segs(n << 1);
        // Y 坐标去重排序，离散化
        set<int> ts;
        int i = 0;
        for (auto& e : rectangles) {
            int x1 = e[0], y1 = e[1], x2 = e[2], y2 = e[3];
            segs[i++] = {x1, y1, y2, 1};
            segs[i++] = {x2, y1, y2, -1};
            ts.insert(y1);
            ts.insert(y2);
        }
        sort(segs.begin(), segs.end());
        unordered_map<int, int> m;
        i = 0;
        for (int v : ts) m[v] = i++;
        vector<int> nums(ts.begin(), ts.end());
        SegmentTree* tree = new SegmentTree(nums);
        long long ans = 0;
        for (int i = 0; i < segs.size(); ++i) {
            auto e = segs[i];
            int x = e[0], y1 = e[1], y2 = e[2], k = e[3];
            if (i > 0) ans += (long long) tree->query() * (x - segs[i - 1][0]);
            tree->modify(1, m[y1], m[y2] - 1, k);
        }
        ans %= mod;
        return (int) ans;
    }
};

作者：lcbin
链接：https://leetcode.cn/problems/rectangle-area-ii/solution/by-lcbin-r8p2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
int main() {



    return 0;
}