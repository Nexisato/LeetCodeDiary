#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//思路：
	//归并法
	//两个数组先进行排序，再用指针遍历两个数组
	//若数组元素不等，则较小的一个数的下标+1；若相等，则两个数组的下标同时+1
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int> result;
		vector<int>::size_type idx1 = 0, idx2 = 0;
		while (idx1 < nums1.size() && idx2 < nums2.size()) {
			if (nums1[idx1] < nums2[idx2]) {
				idx1++;
			} else if (nums1[idx1] > nums2[idx2]) {
				idx2++;
			} else {
				result.push_back(nums1[idx1]);
				idx1++;
				idx2++;
			}
		}
		return result;
	}
	void Print(vector<int>& nums) {
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it += 1) {
			cout << *(it) << endl;
		}
	}
};

int main() {
	vector<int> nums1 = {4, 9, 5};
	vector<int> nums2 = {9, 4, 9, 8, 4};
	Solution ss;
	vector<int> result = ss.intersect(nums1, nums2);
	ss.Print(result);

	return 0;
}