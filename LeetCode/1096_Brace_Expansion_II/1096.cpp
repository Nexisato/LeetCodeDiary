#include <bits/stdc++.h>
using namespace std;

/*
类比中缀表达式，我们需要用到两个栈
*/
class Solution {
private:

public:
    vector<string> braceExpansionII(string expression) {
        vector<string> res;
        vector<int> idxStack;
        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == ',') continue;
            else if (expression[i] == '{') {
                idxStack.push_back(i);
                continue;
            } 
            else if (expression[i] == '}') {
                int right = i, left = idxStack.back();
                idxStack.pop_back();



            }

        }

        return res;

    }
};
int main() {
    set<string> res;
    res.insert("ab");
    res.insert("ac");

    for (auto i = res.begin(); i != res.end(); i++)
        cout << *i << " ";
    cout << endl;

    return 0;
}