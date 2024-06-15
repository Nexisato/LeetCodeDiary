/**
 * @file redbook_1.cpp
 * @Question: 小红背单词
 * @Description:
小红每天都要背单词，然后她会把每天记住了多少单词记录下来，并在小红书上打卡。
当小红背单词时，如果她已经记住了i个单词，且背了一个没有记住的新单词i+1次，则她就会记住这个新单词。

例如，当她按顺序背[“you“、“thank”、"thank”]时，她第一次背单词"you"时她就能记住“you”。
而由于她已经记住了一个单词，所以需要背两次“thank"才能记住"thank”。现在你知道了小红背单词的顺序，请你求出小红今天记住了多少个单词。

输入描述：
第一行一个整数n(1<=n<=10000)。接下来n行，每行一个字符串，保证每个字符串长度不超过 10.

输出描述：
输出一个整数，表示她记住了多少个单词。
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * @brief:
 * 先读取成字符串数组
 * 用 set 记录背过的字符串， map 记录背的字符串的次数
 * 对字符串数组逐元素遍历：
 *  - 若遇到已经记住的字符串，则跳过
 *  - 遇到未记住的字符串，根据 map 的背诵次数判断是否记住
 *      - 若大于 res，则此字符串记住，res++，下次需要记住的字符串需要遇到的次数加1
 */
int main() {
	int n;
	cin >> n;
	vector<string> words;
	for (int i = 0; i < n; ++i) {
		string word;
		cin >> word;
		words.push_back(word);
	}
	int res = 0;
	unordered_set<string> word_membered;
	unordered_map<string, int> table;
	for (int i = 0; i < n; ++i) {
		if (word_membered.count(words[i]))
			continue;
		++table[words[i]];
		if (table[words[i]] > res) {
			++res;
			word_membered.insert(words[i]);
		}
	}

	cout << res << endl;

	return 0;
}