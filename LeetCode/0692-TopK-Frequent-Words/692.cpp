/*
LeetCode 692: Top K Frequent Words
@Description:
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the
same frequency, then the word with the lower alphabetical order comes first.

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.

Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		vector<string> res(k);
		unordered_map<string, int> table;
		for (auto& word : words)
			++table[word];
		//涉及到次序问题，不能直接用greater<>
		auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
			return a.second == b.second ? a.first < b.first : a.second > b.second;
		};
		priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)>
		    minHeap(cmp);
		for (auto& it : table) {
			if (minHeap.size() < k) {
				minHeap.push(it);
				continue;
			}
			if (it.second > table[minHeap.top().first]) {
				minHeap.pop();
				minHeap.push(it);
			}
		}
		for (int i = k - 1; k >= 0; --k) {
			res[i] = minHeap.top().first;
			minHeap.pop();
		}
		return res;
	}
};
int main() {
	vector<string> words{"the", "day", "is",    "sunny", "the",
	                     "the", "the", "sunny", "is",    "is"};
	int k = 4;
	Solution ss;
	vector<string> res = ss.topKFrequent(words, k);
	for (auto& word : res)
		cout << word << " ";
	cout << endl;

	return 0;
}