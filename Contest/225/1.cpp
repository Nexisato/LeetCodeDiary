/*
5661. 替换隐藏数字得到的最晚时间 显示英文描述
给你一个字符串 time ，格式为 hh:mm（小时：分钟），其中某几位数字被隐藏（用 ? 表示）。
有效的时间为 00:00 到 23:59 之间的所有时间，包括 00:00 和 23:59 。
替换 time 中隐藏的数字，返回你可以得到的最晚有效时间。
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string maximumTime(string time) {
		for (int i = 0; i < time.length(); i++) {
			if (time[i] == '?') {
				if (i == 0) {
					if (time[1] == '?')
						time[0] = '2';
					else if (time[1] <= '3')
						time[i] = '2';
					else
						time[i] = '1';
				}
				if (i == 1) {
					if (time[0] == '2') {
						time[i] = '3';
					} else {
						time[i] = '9';
					}
				}
				if (i == 3) {
					time[i] = '5';
				}
				if (i == 4) {
					time[i] = '9';
				}
			}
		}
		return time;
	}
};
/*
思路：
签到题
不需要循环，逐位检查即可，重点在前两位上
坑较多，注意罚时
*/

class Solution_std {
public:
	string maximumTime(string time) {
		if (time[0] == '?') {
			if (time[1] == '?' || time[1] < '4')
				time[0] = '2';
			else
				time[0] = '1';
		}
		if (time[1] == '?') {
			if (time[0] == '2')
				time[1] = '3';
			else
				time[1] = '9';
		}
		if (time[3] == '?')
			time[3] = '5';
		if (time[4] == '?')
			time[4] = '9';
		return time;
	}
};

int main() {
	string test = "??:5?";
	Solution ss;
	cout << ss.maximumTime(test) << endl;
	return 0;
}