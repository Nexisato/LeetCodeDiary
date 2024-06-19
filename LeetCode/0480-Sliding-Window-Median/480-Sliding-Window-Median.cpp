/*
LeetCode 480 : Siliding Windows Median
@Description:
Median is the middle value in an ordered integer list. If the size of the list is even,
there is no middle value. So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3
[2,3], the median is (2 + 3) / 2 = 2.5

Given an array nums, there is a sliding window of size k which is moving from
the very left of the array to the very right. You can only see the k numbers in the
window. Each time the sliding window moves right by one position. Your job is to output
the median array for each window in the original array.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Therefore, return the median sliding window as [1,-1,-1,3,5,6].

Note:
You may assume k is always valid, ie: k is always smaller than input array's size for
non-empty array. Answers within 10^-5 of the actual value will be accepted as correct.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：每个窗口sort（超时）

*/
class Solution {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		if (nums.size() == 0 || k == 0)
			return {};
		int left = 0;
		int right = left + k - 1;
		vector<double> res;
		while (right < nums.size()) {
			vector<int> arr(nums.begin() + left, nums.begin() + right + 1);
			sort(arr.begin(), arr.end());
			res.emplace_back(medianCal(arr));
			++left;
			++right;
		}
		return res;
	}
	double medianCal(vector<int>& nums) {
		if (nums.size() % 2 == 1)
			return (double)nums[nums.size() / 2];
		else {
			return (double)(nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2;
		}
	}
};
/*
思路：
利用multiset数据结构进行处理：
1. 遍历输入的每个元素
2. 若multiset中的元素超过了k个，则删除滑动窗口最左边的 第 i-k 个元素
3. 将遍历到的元素加入到multiset中
4. 若当前位置到达 k - 1，则开始求中位数
*/
class Solution_multiset {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		vector<double> res;
		multiset<double> st;
		for (int i = 0; i < nums.size(); ++i) {
			if (st.size() >= k)
				st.erase(st.find(nums[i - k]));
			st.insert(nums[i]);
			if (i >= k - 1) {
				auto mid = st.begin();
				std::advance(mid, k / 2);
				res.emplace_back((*mid + *prev(mid, (1 - k % 2))) / 2);
			}
		}
		return res;
	}
};
/*
思路：对顶堆
1.
考察中位数的性质：若一个数组中的中位数，大于中位数的数目和小于中位数的数目，要么相等，要么相差1
2. 将数组中前 k 个元素放入大顶堆，在从大顶堆中弹出 k / 2 个元素放入小顶堆中
        -k 为奇数，大顶堆元素数目比小顶堆多 1；k 为偶数，大顶堆数目与小顶堆数目相等
        -k
为奇数，大顶堆top元素为(k个元素的)中位数；k为偶数，两个堆顶元素的平均值即为中位数
3. 滑动窗口时的操作
    - 定义balance表示大顶堆maxHeap与小顶堆minHeap的元素数目之差
    - 设置当前滑动时balance = 0
    - 删除窗口左侧元素
        · 由于堆无法删除指定元素，因此先标记这个元素，note[left]++
        · 假设左侧元素已经删除掉（实际未删），堆的平衡下发生变化，因而
            若nums[left] <= maxHeap.top()，说明删掉的元素在
maxHeap，balance--；从minHeap删除，否则balance++
    - 添加窗口右侧元素
        · 若 nums[right] <=
maxHeap.top()，放入maxHeap，balance++；否则放入minHeap，balance--
    - 增删操作后，balance有如下情况
        · balance == 0，跳过
        · balance == 2，则取出maxHeap元素放入minHeap
        · balance == -2，则取出minHeap元素放入maxHeap
    -
检查两边堆顶元素是否被标记，若标记则弹出，直到堆顶元素不被标记为止（中位数运算只与堆顶元素有关）
*/
class Solution {
private:
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	unordered_map<int, int> note;
	double getMedian(int& k) {
		if (k % 2)
			return (double)maxHeap.top();
		else
			return (long long)(maxHeap.top() + minHeap.top()) / (double)2;
	}

public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		for (int i = 0; i < k; i++)
			maxHeap.emplace(nums[i]);
		for (int i = 0; i < k / 2; i++) {
			minHeap.emplace(maxHeap.top());
			maxHeap.pop();
		}
		vector<double> res{getMedian(k)};
		for (int i = k; i < nums.size(); i++) {
			int balance = 0;
			int left = i - k;
			note[nums[left]]++;

			if (!maxHeap.empty() && nums[left] <= maxHeap.top())
				balance--;
			else
				balance++;

			if (nums[i] <= maxHeap.top()) {
				maxHeap.emplace(nums[i]);
				balance++;
			} else {
				minHeap.emplace(nums[i]);
				balance--;
			}

			if (balance > 0) {
				minHeap.emplace(maxHeap.top());
				maxHeap.pop();
			} else if (balance < 0) {
				maxHeap.emplace(minHeap.top());
				minHeap.pop();
			}

			while (!maxHeap.empty() && note[maxHeap.top()] > 0) {
				note[maxHeap.top()]--;
				maxHeap.pop();
			}
			while (!minHeap.empty() && note[minHeap.top()] > 0) {
				note[minHeap.top()]--;
				minHeap.pop();
			}

			res.emplace_back(getMedian(k));
		}
		return res;
	}
};
int main() { return 0; }