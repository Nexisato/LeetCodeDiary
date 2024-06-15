#include <bits/stdc++.h>
using namespace std;

//基于递归实现的DFS
class Node {};
vector<bool> visited;
bool DFS(Node cur, Node target, vector<bool>& visited) {
	if (cur equal to target)
		return true;
	for (Node next : neighbors of cur) {
		if (!visited[next]) {
			visited[next] = true;
			DFS(next, target, visited);
		}
	}
	return false;
}

int main() { return 0; }