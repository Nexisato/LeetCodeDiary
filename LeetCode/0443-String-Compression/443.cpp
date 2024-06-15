/*
LeetCode 443: String Compression
@Description:
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:
- If the group's length is 1, append the character to s.
- Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead be stored in the input character array chars.
Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
思路：双指针
1. read 指针读原字符数组，write指针用于写入
2. chars[read] != chars[read + 1] 时，记录长度 和 字符
3. 将长度转化为数字字符写回 chars

*/
class Solution {
public:
	int compress(vector<char>& chars) {
		int n = chars.size();
		int read = 0, write = 0;
		int left = 0;
		for (read = 0; read < n; ++read) {
			if (read == n - 1 || chars[read] != chars[read + 1]) {
				chars[write++] = chars[read];
				int l = read - left + 1;
				if (l > 1) {
					string len = to_string(l);
					for (int j = 0; j < len.length(); ++j)
						chars[write++] = len[j];
				}
				left = read + 1;
			}
		}
		return write;
	}
};
int main() { return 0; }