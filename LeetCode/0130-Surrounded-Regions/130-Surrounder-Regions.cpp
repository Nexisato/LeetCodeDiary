/*
LeetCode: 130 Surrounded Regions
Description:
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Explanation:
Surrounded regions shouldn’t be on the border, which means that any 'O' on the border 
of the board are not flipped to 'X'. Any 'O' that is not on the border 
and it is not connected to an 'O' on the border will be flipped to 'X'. 
Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
思路：并查集
1. 虚构空节点作为root parent
2. 二维坐标映射为一维坐标 (x, y) => (x * n + y)
3. board边缘的'O'与root相连
4. board内部（除开边缘）的'O'与同行同列的'O'相连
5. 遍历检查board内部，不与root相连通的节点全部用'X'替换
*/
//常规
class Djset {
private:
    vector<int> parent;  // 记录节点的根
    vector<int> rank;  // 记录根节点的深度（用于优化）
    int count;
public:
    Djset(int n): parent(vector<int>(n)), rank(vector<int>(n)), count(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        // 压缩方式：直接指向根节点
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) 
                swap(rootx, rooty);
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            count--;
        }
    }

    int get_count() {
        return count;
    }

    bool isMerged(int x, int y) {
        return find(x) == find(y);
    }
};
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        int M = board.size();
        int N = board[0].size();
        Djset uf = Djset(M * N + 1);
        int root = M * N;

        for (int i = 0; i < M; i++) {
            if (board[i][0] == 'O')
                uf.merge(i * N + 0, root);
            if (board[i][N - 1] == 'O')
                uf.merge(i * N + N - 1, root);
        }
        for (int j = 0; j < N; j++) {
            if (board[0][j] == 'O')
                uf.merge(0 * N + j, root);
            if (board[M - 1][j] == 'O')
                uf.merge((M - 1) * N + j, root);
        }
        int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        for (int i = 1; i < M - 1; i++)
            for (int j = 1; j < N - 1; j++) 
                if (board[i][j] == 'O')
                    for (int k = 0; k < 4; k++) {
                        int x = i + d[k][0];
                        int y = j + d[k][1];
                        if (board[x][y] == 'O')
                            uf.merge(x * N + y, i * N + j);
                    }
        for (int i = 1; i < M; i++) 
            for (int j = 1; j < N; j++)
                if (!uf.isMerged(i * N + j, root))
                    board[i][j] = 'X';
    }
};
void Print(vector<vector<char>> board) {
    int M = board.size();
    int N = board[0].size();
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << "\t";
        }
        cout << "\n";
    }
}
int main() {
    vector<vector<char>> board{
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    Print(board);
    Solution ss;
    ss.solve(board);
    Print(board);
    return 0;
}