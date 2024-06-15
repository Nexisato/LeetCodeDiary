/*
LeetCode 765: Couples Holding Hands
@Description:
N couples sit in 2N seats arranged in a row and want to hold hands.
We want to know the minimum number of swaps so that every couple is sitting side by side.
A swap consists of choosing any two people, then they stand up and switch seats.

The people and seats are represented by an integer from 0 to 2N-1, the couples are numbered in order,
the first couple being (0, 1), the second couple being (2, 3),
and so on with the last couple being (2N-2, 2N-1).

The couples' initial seating is given by row[i] being the value of the person
who is initially sitting in the i-th seat.

Note:
len(row) is even and in the range of [4, 60].
row is guaranteed to be a permutation of 0...len(row)-1.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：并查集
*/
class Djset {
private:
	vector<int> parent; // 记录节点的根
	vector<int> rank;   // 记录根节点的深度（用于优化）
	int count;

public:
	Djset(int n) : parent(vector<int>(n)), rank(vector<int>(n)), count(n) {
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
			if (rank[rootx] == rank[rooty])
				rank[rootx] += 1;
			count--;
		}
	}

	int get_count() { return count; }

	bool isMerged(int x, int y) { return find(x) == find(y); }
};
class Solution {
public:
	int minSwapsCouples(vector<int>& row) { int res = 0; }
};
/*
思路：异或运算
1. 2k XOR 1 = 2k + 1；2k + 1 XOR 1 = 2k
*/
class Solution_XOR {
public:
	int minSwapsCouples(vector<int>& row) {
		int res = 0;
		for (int i = 0; i < row.size(); i += 2) {
			if (row[i] == (row[i + 1] ^ 1))
				continue;
			for (int j = i + 1; j < row.size(); ++j)
				if ((row[j] ^ 1) == row[i]) {
					swap(row[i + 1], row[j]);
					++res;
					break;
				}
		}
		return res;
	}
};
int main() { return 0; }