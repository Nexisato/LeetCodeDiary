/*
 * @Date: 2024-02-08 09:35:21
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0427-Contruct-QuadTree/427.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

/**
* 思路：建树
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        const int n = grid.size();
        if (n == 0) return nullptr;
        Node* root = new Node();
        bool isLeaf = true;
        for (int i = 0; i < n; ++i)
            if (grid[i][0] != grid[0][0]) {
                isLeaf = false;
                break;
            }
        if (isLeaf) {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (grid[i][j] != grid[0][0]) {
                        isLeaf = false;
                        break;
                    }
        }
        if (isLeaf) {
            root->val = grid[0][0];
            root->isLeaf = true;
            return root;
        }

        vector<vector<int>> topLeft(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> topRight(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> bottomLeft(n / 2, vector<int>(n / 2, 0));
        vector<vector<int>> bottomRight(n / 2, vector<int>(n / 2, 0));
        for (int i = 0; i < n / 2; ++i)
            for (int j = 0; j < n / 2; ++j) {
                topLeft[i][j] = grid[i][j];
                topRight[i][j] = grid[i][j + n / 2];
                bottomLeft[i][j] = grid[i + n / 2][j];
                bottomRight[i][j] = grid[i + n / 2][j + n / 2];
            }
        root->topLeft = construct(topLeft);
        root->topRight = construct(topRight);
        root->bottomLeft = construct(bottomLeft);
        root->bottomRight = construct(bottomRight);
        return root;
    }
};

int main() {

    return 0;
}