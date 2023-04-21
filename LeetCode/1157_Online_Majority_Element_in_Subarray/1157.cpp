#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * 思路：线段树 + 摩尔投票 （未归档
 * 
 */
//TODO: 线段树的代码模板整理
class MajorityChecker {
private:
    vector<int> arr;
    unordered_map<int, int> table;
    vector<int> preCount;
public:
    MajorityChecker(vector<int>& arr) {
        this->arr = arr;
        preCount.resize(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            ++table[arr[i]];
            preCount[i] = table[arr[i]];
        }

    }
    
    int query(int left, int right, int threshold) {
        int res = -1;
        for (int i = left; i <= right; ++i) {
            
        }
        return res;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
int main() {

    return 0;
}