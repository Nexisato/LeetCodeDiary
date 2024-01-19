/*
LeetCode 208: Implement Trie (Prefix Tree)
@Description:
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently 
store and retrieve keys in a dataset of strings. There are various applications of this data structure, 
such as autocomplete and spellchecker.

Implement the Trie class:
- Trie() Initializes the trie object.
- void insert(String word) Inserts the string word into the trie.
- boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), 
and false otherwise.
- boolean startsWith(String prefix) Returns true if there is a previously inserted string word 
that has the prefix prefix, and false otherwise.

Constraints:
1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 10^4 calls in total will be made to insert, search, and startsWith.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
*/
class Trie {
private:
    bool isEnd;
    Trie* next[26]; //字母映射表 
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    /** Inserts a word into the trie. 
     * 从根节点的子节点开始与word的第一个字符进行匹配，一直匹配到前缀树链上没有对应字符。
     * 开辟新节点，直到插入完word的最后一个字符，并置最后一个节点 isEnd = true
     * @param word
     * @return null
     * 
    */
    void insert(string word) {
        Trie* node = this;
        for (auto c : word) {
            if (node->next[c - 'a'] == nullptr) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. 
     * 从根节点的子节点开始与word的第一个字符进行匹配，一直匹配到前缀树链上没有对应字符。
     *  - 若此时未到字符串word结尾，返回false
     *  - 若此时已到字符串word结尾，判断该节点是否为isEnd
     * @param word
     * @return true/false
    */
    bool search(string word) {
        Trie* node = this;
        for (auto c : word) {
            node = node->next[c - 'a'];
            if (node == nullptr)
                return false;
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix.
     * 从根节点的子节点开始与word的第一个字符进行匹配，一直匹配到前缀树链上没有对应字符，
     *    - 若已经遍历完word字符串，返回true
     *    - 若未遍历完word字符串，返回false
     * @param prefix
     * @return true/false
     */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (auto c : prefix) {
            node = node->next[c - 'a'];
            if (node == nullptr)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main() {

    return 0;
}