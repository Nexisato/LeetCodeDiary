/*
 * @Date: 2024-02-07 10:27:05
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0068-Text-Justification/68.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/**
 * 思路：
*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        const int n = words.size();
        int i = 0;
        while (i < n) {
            int j = i + 1;
            int len = words[i].size();
            // 找到一行能放下的单词
            while (j < n && len + words[j].size() + j - i <= maxWidth) {
                len += words[j].size();
                ++j;
            }
            string line;
            // 如果是最后一行或者只有一个单词
            // 则左对齐，右边补空格
            if (j == n || j - i == 1) {
                line += words[i];
                for (int k = i + 1; k < j; ++k) {
                    line += " " + words[k];
                }
                while (line.size() < maxWidth) {
                    line += " ";
                }
            } else {
                // 否则，计算每个单词之间的空格数
                // 以及额外的空格数
                // 间隔数： j - i - 1
                // 总空格数： maxWidth - len
                
                int space = (maxWidth - len) / (j - i - 1);
                int extra = (maxWidth - len) % (j - i - 1);
                line += words[i];
                for (int k = i + 1; k < j; ++k) {
                    for (int s = 0; s < space; ++s) {
                        line += " ";
                    }
                    if (extra-- > 0) {
                        line += " ";
                    }
                    line += words[k];
                }
            }
            res.push_back(line);
            i = j;
        }
        

        return res;
    }
};
int main() {
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    Solution ss;
    vector<string> res = ss.fullJustify(words, maxWidth);
    for (auto &s : res) {
        cout << s << endl;
    }

    return 0;
}