#include <vector>
#include <list>
using namespace std;


class SnapshotArray {
private:
    int cur_snap_id;
    vector<list<pair<int, int>>> _data;
public:
    SnapshotArray(int length) {
        this->cur_snap_id = 0;
        _data.resize(length);
    }
    
    void set(int index, int val) {
        this->_data[index].push_back({this->cur_snap_id, val});
    }
    
    int snap() {
        return this->cur_snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto it = this->_data[index].rbegin();
        while (it != this->_data[index].rend() && it->first > snap_id) {
            ++it;
        }
        return it == this->_data[index].rend() ? 0 : it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */



int main() {


    
    return 0;
}