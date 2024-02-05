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
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;
/*
思路：这个比较占空间
*/
class Trie {
private:
    bool isEnd;
    Trie* next[26]; //字母映射表 
    unordered_map<char, Trie*> children;
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
        children.clear();
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
class Trie {
private:
    bool isEnd;
    unordered_map<char, Trie*> next;
public:
    Trie() {
        this->isEnd = false;
        this->next.clear();
    }
    
    void insert(string word) {
        Trie *node = this;
        for (auto& c : word) {
            if (!node->next.count(c))
                node->next[c] = new Trie();
            node = node->next[c];
        }
        node->isEnd = true;
    }
    
    bool search(string word) const {
        const Trie *node = this;
        for (auto& c : word) {
            if (!node->next.count(c))
                return false;
            node = node->next.at(c);
        }
        return node->isEnd == true;
    }
    
    bool startsWith(string prefix) const {
        const Trie *node = this;
        for (auto& c : prefix) {
            if (!node->next.count(c))
                return false;
            node = node->next.at(c);
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

/**
 * 优化：使用哈希表 + 内存池
*/

// class Trie {
// private:
//     bool isEnd;
//     unordered_map<char, Trie*> next;
    
//     static std::vector<Trie*> pool;
// public:
//     Trie() : isEnd(false) {}
//     /*
//     * 重载运算符 new 和 delete，实现内存池
//     * new 就是从内存池中取出一个节点，如果内存池为空，则调用系统的 new
//     * 从内存池取出节点时，需要手动初始化
//     */
//     void* operator new(size_t size) {
//         if (!pool.empty()) {
//             Trie* node = pool.back();
//             pool.pop_back();
//             node->isEnd = false;
//             node->next.clear();
//             return node;
//         }
//         return ::operator new(size);
//     }

//     // delete 就是将节点放回内存池
//     void operator delete(void* p) {
//         pool.push_back(static_cast<Trie*>(p));
//     }

//     static void clearPool() {
//         for (auto& p : pool) {
//             ::operator delete(p);
//         }
//         pool.clear();
//     }

//     ~Trie() {
//         for (auto& p : next) {
//             delete p.second;
//         }
//     }
    
//     void insert(string word) {
//         Trie *node = this;
//         for (auto& c : word) {
//             if (!node->next.count(c))
//                 node->next[c] = new Trie();
//             node = node->next[c];
//         }
//         node->isEnd = true;
//     }
    
//     bool search(string word) const {
//         const Trie *node = this;
//         for (auto& c : word) {
//             if (!node->next.count(c))
//                 return false;
//             node = node->next.at(c);
//         }
//         return node->isEnd == true;
//     }
    
//     bool startsWith(string prefix) const {
//         const Trie *node = this;
//         for (auto& c : prefix) {
//             if (!node->next.count(c))
//                 return false;
//             node = node->next.at(c);
//         }
//         return true;
//     }
// };
// std::vector<Trie*> Trie::pool;

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