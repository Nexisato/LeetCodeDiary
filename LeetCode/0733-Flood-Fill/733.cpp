/*
LeetCode 733: Flood Fill
@Description:
An image is represented by a 2-D array of integers, each integer representing the pixel
value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the
flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected
4-directionally to the starting pixel of the same color as the starting pixel, plus any
pixels connected 4-directionally to those pixels (also with the same color as the
starting pixel), and so on. Replace the color of all of the aforementioned pixels with
the newColor.

At the end, return the modified image.

Note:
The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc <
image[0].length. The value of each color in image[i][j] and newColor will be an integer
in [0, 65535].
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：DFS
*/
class Solution {
private:
	void dfs(vector<vector<int>>& image, int r, int c, int newColor,
	         vector<bool>& visited) {
		int m = image.size(), n = image[0].size();
		int rawColor = image[r][c];
		image[r][c] = newColor;
		visited[r * n + c] = true;

		if (r - 1 >= 0 && image[r - 1][c] == rawColor && !visited[(r - 1) * n + c])
			dfs(image, r - 1, c, newColor, visited);
		if (r + 1 < m && image[r + 1][c] == rawColor && !visited[(r + 1) * n + c])
			dfs(image, r + 1, c, newColor, visited);
		if (c - 1 >= 0 && image[r][c - 1] == rawColor && !visited[r * n + c - 1])
			dfs(image, r, c - 1, newColor, visited);
		if (c + 1 < n && image[r][c + 1] == rawColor && !visited[r * n + c + 1])
			dfs(image, r, c + 1, newColor, visited);
	}

public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
	                              int newColor) {
		int m = image.size(), n = image[0].size();
		vector<bool> visited(m * n, false);
		dfs(image, sr, sc, newColor, visited);
		return image;
	}
};
int main() {
	vector<vector<int>> image{{0, 0, 0}, {0, 1, 1}};
	int sr = 1;
	int sc = 1;
	int newColor = 1;
	Solution ss;
	vector<vector<int>> res = ss.floodFill(image, sr, sc, newColor);

	return 0;
}