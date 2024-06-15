/*
 * @Date: 2024-01-22 09:23:00
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0380-O1-Insert/380.cpp
 * @Description:
 */
#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
private:
	// value -> index
	unordered_map<int, int> table;
	vector<int> elements;

public:
	RandomizedSet() { srand(time(nullptr)); }
	// 新元素，插到末尾
	bool insert(int val) {
		if (table.count(val))
			return false;
		table[val] = elements.size();
		elements.push_back(val);
		return true;
	}

	bool remove(int val) {
		if (!table.count(val))
			return false;
		// 原本处于末尾的元素，移到 val 的位置
		int lastVal = elements.back();
		int valIdx = table[val];
		elements[valIdx] = lastVal;
		table[lastVal] = valIdx;

		// 删除末尾元素
		elements.pop_back();
		table.erase(val);
		return true;
	}

	int getRandom() {
		int randIdx = rand() % elements.size();
		return elements[randIdx];
	}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main() { return 0; }