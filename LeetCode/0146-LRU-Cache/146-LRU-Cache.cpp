/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0146-LRU-Cache/146-LRU-Cache.cpp
 * @Description: 
 */
/*
LeetCode 146: LRU Cache
@Description:
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. 
Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
Follow up:
Could you do get and put in O(1) time complexity?

Constraints:
1 <= capacity <= 3000
0 <= key <= 3000
0 <= value <= 10^4
At most 3 * 10^4 calls will be made to get and put
*/
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
/*
思路：
LeastRecentlyUsed特性：快速CRUD，有顺序之分
 list + hash
构建新数据结构：hash双向链表
*/
class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> table;
public:
    LRUCache(int capacity) : cap(capacity) {
    }
    
    int get(int key) {
        if (table.find(key) == table.end())
            return -1;
        auto k_v = *table[key];
        cache.erase(table[key]);
        cache.push_front(k_v);
        table[key] = cache.begin();
        return k_v.second;
    }
    
    void put(int key, int value) {
        if (table.find(key) == table.end()) {
            if (cache.size() == cap) {
                table.erase(cache.back().first);
                cache.pop_back();
            }
        }
        else
            cache.erase(table[key]);
        cache.push_front({key, value});
        table[key] = cache.begin();
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {

    return 0;
}