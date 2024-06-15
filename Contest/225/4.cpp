/*
5664. 放置盒子
You have a cubic storeroom where the width, length, and height of the room are all equal to n units.
You are asked to place n boxes in this room where each box is a cube of unit side length.
There are however some rules to placing the boxes:

You can place the boxes anywhere on the floor.
If box x is placed on top of the box y, then each side of the four vertical sides of
the box y must either be adjacent to another box or to a wall.
Given an integer n, return the minimum possible number of boxes touching the floor.

Constraints:
0 <= n <= 10^9
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
假设地面上的盒子为 k ，从 k = 1 开始，每多一个盒子，可以放置的总盒子数为  1 2 1 2 3 1 2 3 4 1...
k = n * (n + 1) / 2 时，需要可以放置的盒子数置为1，直到下一次 (n + 1) * (n + 2) / 2 出现，则
*/
class Solution {
public:
	int minimumBoxes(int n) {
		int bottom = 1;
		for (int sum = 1, height = 1; sum < n; height++)
			for (int i = 0; i <= height && sum < n; i++) {
				bottom++;
				sum += i + 1;
			}
		return bottom;
	}
};

int main() { return 0; }