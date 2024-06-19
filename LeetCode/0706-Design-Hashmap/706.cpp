/*
LeetCode 706: Design Hashmap
@Description:
Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:
MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap.
If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped,
or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the
mapping for the key.

Constraints:
0 <= key, value <= 10^6
At most 10^4 calls will be made to put, get, and remove.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：数组存储（开销过大） or 链式存储
*/
class MyHashMap {
private:
	const int MAX = 1000001;
	vector<int> table;

public:
	/** Initialize your data structure here. */
	MyHashMap() { table = vector<int>(MAX, -1); }

	/** value will always be non-negative. */
	void put(int key, int value) {
		int k = key % MAX;
		table[k] = value;
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map
	 * contains no mapping for the key */
	int get(int key) { return table[key % MAX]; }

	/** Removes the mapping of the specified value key if this map contains a mapping
	 * for the key */
	void remove(int key) { table[key % MAX] = -1; }
};
/*
基于拉链法
*/
class MyHashMap {
private:
	vector<list<pair<int, int>>> table;
	static const int MAX = 768;
	static int hash(int key) { return key % MAX; }

public:
	/** Initialize your data structure here. */
	MyHashMap() : table(MAX) {}

	/** value will always be non-negative. */
	void put(int key, int value) {
		int k = hash(key);
		for (auto it = table[k].begin(); it != table[k].end(); ++it) {
			if (it->first == key) {
				it->second = value;
				return;
			}
		}
		table[k].push_back(make_pair(key, value));
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map
	 * contains no mapping for the key */
	int get(int key) {
		int k = hash(key);
		for (auto it = table[k].begin(); it != table[k].end(); ++it)
			if (it->first == key)
				return it->second;
		return -1;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping
	 * for the key */
	void remove(int key) {
		int k = hash(key);
		for (auto it = table[k].begin(); it != table[k].end(); ++it)
			if (it->first == key) {
				table[k].erase(it);
				return;
			}
	}
};
int main() { return 0; }