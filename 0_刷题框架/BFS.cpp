/*

*/
#include <bits/stdc++.h>
using namespace std;
/*
    基于队列实现的BFS模板
*/
class Node {};

int BFS(Node root, Node target) {
    queue<Node> q;
    q.push(root);
    int step = 0;
    while (!q.empty()) {
        ++step;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Node cur = q.front();
            q.pop();
            if (target equal to  cur)
                return step;
            for (Node next : the neighbors of cur)
                q.push(next);
        }
    }
    return -1;/*Search Failure*/
};

/*
    保证每一个节点不会被重复遍历
*/
int BFS_without_repeatation(Node root, Node target) {
    queue<Node> q;
    set<Node> used;
    int step = 0;
    q.push(root);
    used.insert(root);

    while (!q.empty()) {
        int size = q.size();
        step += 1;
        for (int i = 0; i < size; ++i) {
            Node cur = q.front();
            q.pop();
            if (cur is equal to target)
                return step;
            for (Node next : neighbors of cur)
                if (used.find(used) == used.end()) {
                    q.push(next);
                    used.insert(next);
                }
        }
    }

    return -1; /*Search Failure*/
}


















int main() {


    return 0;
}