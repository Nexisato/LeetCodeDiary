/*
LeetCode: 341 Flateen Nested List Iterator
Description:
Given a nested list of integers, implement an iterator to flatten it.
Each element is either an integer, or a list -- whose elements may also be integers or other lists.
*/
#include <bits/stdc++.h>
using namespace std;
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const; 
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
    //const 放在函数前，表示返回值不可修改；放在函数后，表示该函数不可修改成员变量，不可调用非const成员函数
    //const修饰的对象只能调用const（放在后面的）成员函数
};
/*
思路：DFS
嵌套的整型列表就是一个树，叶子节点为整数，非叶子节点为一个嵌套列表
我们可以将所有整数写入一个数组，然后遍历该数组
*/ 
class NestedIterator {
private:
    vector<int> arr;
    vector<int>::iterator it;
    void dfs(const vector<NestedInteger>& nestedList) {
        for (auto &nest : nestedList) {
            if (nest.isInteger())
                arr.emplace_back(nest.getInteger());
            else
                dfs(nest.getList());
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        it = arr.begin();
    }
    
    int next() {
        return *(it++);
    }
    
    bool hasNext() {
        return (it != arr.end());
    }
};
/*
思路2：迭代+栈
1. 构造函数时，我们需要将nestedList中的所有元素【逆序】存入栈中
2. 调用hasNext()函数时，访问栈顶元素，分为如下情况
    - 栈顶元素为int值，则返回true，并弹出元素
    - 栈顶元素为列表，需要将列表摊开，并将列表中的所有元素逆序放入栈中
    - 栈为空，返回false即可
*/
class NestedIterator_it {
private:
    stack<NestedInteger> st;
public:
    NestedIterator_it(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for (int i = n - 1; i >= 0; --i)
            st.push(nestedList[i]);
    }
    int next() {
        NestedInteger cur = st.top();
        st.pop();
        return cur.getInteger();
    }
    bool hasNext() {
        while (!st.empty()) {
            NestedInteger cur = st.top();
            if (cur.isInteger())
                return true;
            st.pop();
            vector<NestedInteger> curList = cur.getList();
            int m = curList.size();
            for (int i = m - 1; i >= 0; --i)
                st.push(curList[i]);
        }
        return false;
    }
};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
int main() {

    return 0;
}