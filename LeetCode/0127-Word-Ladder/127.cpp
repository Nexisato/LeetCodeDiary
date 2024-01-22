/*
 * @Date: 2024-01-19 12:03:08
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0127-Word-Ladder/127.cpp
 * @Description: 
 */
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;


class Solution {
public:
    // 等价于 433-基因突变，也是 BFS 的模板题
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return 0;
        vector<bool> isVisited(wordList.size(), false);
        queue<string> q;
        q.push(beginWord);
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            ++res;
            for (int i = 0; i < size; ++i) {
                string cur = q.front();
                q.pop();
                for (int k = 0; k < wordList.size(); ++k) {
                    int diff = 0;
                    if (isVisited[k]) continue;
                    for (int j = 0; j < beginWord.size(); ++j) {
                        if (cur[j] != wordList[k][j]) ++diff;
                    }
                    if (diff == 1) {
                        if (wordList[k] == endWord) return res + 1;
                        q.push(wordList[k]);
                        isVisited[k] = true;  
                    }
                }
            }
        }
        return 0;
    }
};
int main() {

    return 0;
}