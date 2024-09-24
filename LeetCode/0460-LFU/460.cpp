#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LFUCache {
private:
    struct node_t {
        int key;
        int val;
        int count = 0;

        node_t(int k, int v): key(k), val(v), count(1) {}
        node_t(int k, int v, int _count): key(k), val(v), count(_count) {}
        node_t& operator=(const node_t& other) {
            this->key = other.key;
            this->val = other.val;
            this->count = other.count;
            return *this;
        }
    };
    typedef list<node_t>::iterator ite;
private:
    int _capacity;
    int min_count = 1;
    unordered_map<int, ite> key_table;
    unordered_map<int, list<node_t>> freq_table;
public:
    LFUCache(int capacity): _capacity(capacity) {
        min_count = 1;
        key_table.clear();
        freq_table.clear();
    }
    
    int get(int key) {
        if (_capacity == 0) return -1;
        auto kv_iter = key_table.find(key);
        if (kv_iter == key_table.end()) return -1;
        ite node_iter = key_table.at(key);
        
        int val = node_iter->val;
        int count = node_iter->count;
        freq_table[count].erase(node_iter);
        if (freq_table[count].size() == 0) {
            freq_table.erase(count);
            if (min_count == count) ++min_count;
        }
        ++count;
        freq_table[count].push_front(node_t(key, val, count));
        key_table[key] = freq_table[count].begin();

        return val;
        
    }
    
    void put(int key, int value) {
        if (_capacity <= 0) return;

        if (this->get(key) != -1) {
            auto node_iter = key_table.at(key);
            node_iter->val = value;
        } else {
            if (key_table.size() >= _capacity) {
                auto last_node = freq_table[min_count].back();
                key_table.erase(last_node.key);
                freq_table[min_count].pop_back();
            }
            node_t cur_node = node_t(key, value, 1);
            freq_table[cur_node.count].push_front(cur_node);
            key_table[key] = freq_table[cur_node.count].begin();
            
            // 更新 min_count
            min_count = cur_node.count;
        }
    }
};

int main() { 

    return 0;
}