/**
 * 汉诺塔问题
 */
#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        function<void(int, vector<int>&, vector<int>&, vector<int>&)> moves =
            [&](int n, vector<int>& A, vector<int>& B, vector<int>& C) {
                if (n == 1) {
                    C.push_back(A.back());
                    A.pop_back();
                    return;
                }
                moves(n - 1, A, C, B);
                C.push_back(A.back());
                A.pop_back();
                moves(n - 1, B, A, C);
            };
        moves(n, A, B, C);
    }
};

int main() { return 0; }