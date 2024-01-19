#include <bits/stdc++.h>
using namespace std;
/**
 * @brief 
 * 字典树，反过来处理后缀
 * 注意传引用，减去传值的拷贝时间消耗
 * 
 */
class Trie {
private:
    bool isEnd = false;
    Trie *next[26];
public:
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    void insert(string& word) {
        Trie *node = this;
        for (char c : word) {
            if (!node->next[c - 'a'])
                node->next[c - 'a'] = new Trie();
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }
    bool startWith(string& prefix) {
        Trie *node = this;
        for (int i = prefix.size() - 1, j = 0; ~i && j < 201; --i, ++j) {
            int idx = prefix[i] - 'a';
            if (!node->next[idx])
                return false;
            node = node->next[idx];            
            if (node->isEnd)
                return true;
        }
        return false;
    }

};


class StreamChecker {
private:
    Trie *trie = new Trie();
    string s = "";
public:
    StreamChecker(vector<string>& words) {
        for (auto& word : words) {
            reverse(word.begin(), word.end());
            trie->insert(word);
        }

    }
    
    bool query(char letter) {
        s += letter;
        return trie->startWith(s);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

int main() {
    vector<string> words({"cd", "f", "kl"});
    StreamChecker* ss = new StreamChecker(words);
    ss->query('a');
    ss->query('b');
    ss->query('c');
    ss->query('d');

    cout << ss->query('d') << endl;


    return 0;
}