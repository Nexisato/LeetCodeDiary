/*
LeetCode 705: Design Hashset
@Description:
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:
void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the
HashSet, do nothing.

Constraints:
0 <= key <= 10^6
At most 10^4 calls will be made to add, remove, and contains.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：数组 or 拉链链表
*/
const int MAX = 10001;
class MyHashSet {
private:
	vector<vector<int>> table;
	int mod;

public:
	/** Initialize your data structure here. */
	MyHashSet() {
		mod = MAX;
		table = vector<vector<int>>(mod);
	}

	void add(int key) {
		int k = key % mod;
		bool insertFlag = true;
		for (auto it = table[k].begin(); it != table[k].end(); ++it)
			if (*it == key)
				insertFlag = false;
		if (insertFlag)
			table[k].push_back(key);
	}

	void remove(int key) {
		int k = key % mod;
		for (auto it = table[k].begin(); it != table[k].end(); ++it)
			if (*it == key) {
				table[k].erase(it);
				return;
			}
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		int k = key % mod;
		for (auto it = table[k].begin(); it != table[k].end(); ++it)
			if (*it == key)
				return true;
		return false;
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
int main() { return 0; }