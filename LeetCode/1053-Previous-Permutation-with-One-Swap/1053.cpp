#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * 倒序寻找第一个递减的序列对，最大化这个递减的位置
 *
 */
class Solution {
public:
	vector<int> prevPermOpt1(vector<int>& arr) {
		int n = arr.size();
		for (int i = n - 2; i >= 0; --i) {
			if (arr[i] > arr[i + 1]) {
				int j = n - 1;
				while (arr[j] >= arr[i] || arr[j] == arr[j - 1])
					--j;
				swap(arr[i], arr[j]);
				break;
			}
		}
		return arr;
	}
};
int main() { return 0; }