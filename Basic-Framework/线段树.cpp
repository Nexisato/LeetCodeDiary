#include <iostream>
#include <vector>
using namespace std;


template <typename T>
class SegmentTree {
public:
    SegmentTree(const std::vector<T>& data) {
        n = data.size();
		// 为什么是 4 * n: 因为线段树是一棵满二叉树，n 个叶子节点，有 n - 1 个非叶子节点
        tree.resize(4 * n);
        build(data, 0, 0, n - 1);
    }

    // 区间查询 [left, right]
    T query(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }

    // 区间修改 [left, right] 的值，加上 delta
    void update(int left, int right, T delta) {
        update(0, 0, n - 1, left, right, delta);
    }

private:
    int n;
    std::vector<T> tree;

    // 构建线段树
    void build(const std::vector<T>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node + 1, start, mid);
            build(data, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // 区间查询 [left, right]
    T query(int node, int start, int end, int left, int right) {
        if (right < start || end < left) {
            return 0;
        }
        if (left <= start && end <= right) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        T left_sum = query(2 * node + 1, start, mid, left, right);
        T right_sum = query(2 * node + 2, mid + 1, end, left, right);
        return left_sum + right_sum;
    }

    // 区间修改 [left, right] 的值，加上 delta
    void update(int node, int start, int end, int left, int right, T delta) {
        if (right < start || end < left) {
            return;
        }
        if (start == end) {
            tree[node] += delta;
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node + 1, start, mid, left, right, delta);
        update(2 * node + 2, mid + 1, end, left, right, delta);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
};

/*
将每个长度不为1的区间划分为左右两个区间递归求解，将整个线段划分为一个树形结构，
通过合并左右两个区间来求得该区间的信息。通过这种数据结构可以方便进行大部分的区间操作。
*/

/*可以区间加、求和的线段树模板*/
template <typename T> class SegTreeLazyRangeAdd {
	vector<T> tree, lazy;
	vector<T>* arr;
	int n, root, n4, end;

	void maintain(int cl, int cr, int p) {
		int cm = cl + (cr - cl) / 2;
		if (cl != cr && lazy[p]) {
			lazy[p * 2] += lazy[p];
			lazy[p * 2 + 1] += lazy[p];
			tree[p * 2] += lazy[p] * (cm - cl + 1);
			tree[p * 2 + 1] += lazy[p] * (cr - cm);
			lazy[p] = 0;
		}
	}

	T range_sum(int l, int r, int cl, int cr, int p) {
		if (l <= cl && cr <= r)
			return tree[p];
		int m = cl + (cr - cl) / 2;
		T sum = 0;
		maintain(cl, cr, p);
		if (l <= m)
			sum += range_sum(l, r, cl, m, p * 2);
		if (r > m)
			sum += range_sum(l, r, m + 1, cr, p * 2 + 1);
		return sum;
	}

	void range_add(int l, int r, T val, int cl, int cr, int p) {
		if (l <= cl && cr <= r) {
			lazy[p] += val;
			tree[p] += (cr - cl + 1) * val;
			return;
		}
		int m = cl + (cr - cl) / 2;
		maintain(cl, cr, p);
		if (l <= m)
			range_add(l, r, val, cl, m, p * 2);
		if (r > m)
			range_add(l, r, val, m + 1, cr, p * 2 + 1);
		tree[p] = tree[p * 2] + tree[p * 2 + 1];
	}

	void build(int s, int t, int p) {
		if (s == t) {
			tree[p] = (*arr)[s];
			return;
		}
		int m = s + (t - s) / 2;
		build(s, m, p * 2);
		build(m + 1, t, p * 2 + 1);
		tree[p] = tree[p * 2] + tree[p * 2 + 1];
	}

public:
	explicit SegTreeLazyRangeAdd<T>(vector<T> v) {
		n = v.size();
		n4 = n * 4;
		tree = vector<T>(n4, 0);
		lazy = vector<T>(n4, 0);
		arr = &v;
		end = n - 1;
		root = 1;
		build(0, end, 1);
		arr = nullptr;
	}

	void show(int p, int depth = 0) {
		if (p > n4 || tree[p] == 0)
			return;
		show(p * 2, depth + 1);
		for (int i = 0; i < depth; ++i)
			putchar('\t');
		printf("%d:%d\n", tree[p], lazy[p]);
		show(p * 2 + 1, depth + 1);
	}

	T range_sum(int l, int r) { return range_sum(l, r, 0, end, root); }

	void range_add(int l, int r, int val) { range_add(l, r, val, 0, end, root); }
};

/*可以区间修改的线段树模板*/
template <typename T> class SegTreeLazyRangeSet {
	vector<T> tree, lazy;
	vector<T>* arr;
	int n, root, n4, end;

	void maintain(int cl, int cr, int p) {
		int cm = cl + (cr - cl) / 2;
		if (cl != cr && lazy[p]) {
			lazy[p * 2] = lazy[p];
			lazy[p * 2 + 1] = lazy[p];
			tree[p * 2] = lazy[p] * (cm - cl + 1);
			tree[p * 2 + 1] = lazy[p] * (cr - cm);
			lazy[p] = 0;
		}
	}

	T range_sum(int l, int r, int cl, int cr, int p) {
		if (l <= cl && cr <= r)
			return tree[p];
		int m = cl + (cr - cl) / 2;
		T sum = 0;
		maintain(cl, cr, p);
		if (l <= m)
			sum += range_sum(l, r, cl, m, p * 2);
		if (r > m)
			sum += range_sum(l, r, m + 1, cr, p * 2 + 1);
		return sum;
	}

	void range_set(int l, int r, T val, int cl, int cr, int p) {
		if (l <= cl && cr <= r) {
			lazy[p] = val;
			tree[p] = (cr - cl + 1) * val;
			return;
		}
		int m = cl + (cr - cl) / 2;
		maintain(cl, cr, p);
		if (l <= m)
			range_set(l, r, val, cl, m, p * 2);
		if (r > m)
			range_set(l, r, val, m + 1, cr, p * 2 + 1);
		tree[p] = tree[p * 2] + tree[p * 2 + 1];
	}

	void build(int s, int t, int p) {
		if (s == t) {
			tree[p] = (*arr)[s];
			return;
		}
		int m = s + (t - s) / 2;
		build(s, m, p * 2);
		build(m + 1, t, p * 2 + 1);
		tree[p] = tree[p * 2] + tree[p * 2 + 1];
	}

public:
	explicit SegTreeLazyRangeSet<T>(vector<T> v) {
		n = v.size();
		n4 = n * 4;
		tree = vector<T>(n4, 0);
		lazy = vector<T>(n4, 0);
		arr = &v;
		end = n - 1;
		root = 1;
		build(0, end, 1);
		arr = nullptr;
	}

	void show(int p, int depth = 0) {
		if (p > n4 || tree[p] == 0)
			return;
		show(p * 2, depth + 1);
		for (int i = 0; i < depth; ++i)
			putchar('\t');
		printf("%d:%d\n", tree[p], lazy[p]);
		show(p * 2 + 1, depth + 1);
	}

	T range_sum(int l, int r) { return range_sum(l, r, 0, end, root); }

	void range_set(int l, int r, int val) { range_set(l, r, val, 0, end, root); }
};