/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0133_Clone_Graph/133.cpp
 * @Description:
 */
/*
LeetCode 133: Clone Graph
@Description:
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed).
For example, the first node with val == 1, the second node with val == 2, and so on.
The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph.
Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference
to the cloned graph.

Constraints:
The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};
/*
思路：DFS
建立哈希表保存克隆节点，key为原始图中的Node节点，value为克隆图中的对应节点，避免死循环
*/
class Solution {
public:
	unordered_map<Node*, Node*> visited;
	Node* cloneGraph(Node* node) {
		if (node == nullptr)
			return nullptr;
		//原始图的node节点已访问
		if (visited.count(node))
			return visited[node];

		//深copy，不保留node的neighbors
		Node* cloneNode = new Node(node->val);
		visited[node] = cloneNode;

		for (auto& next : node->neighbors)
			cloneNode->neighbors.emplace_back(cloneGraph(next));

		return cloneNode;
	}
};

int main() { return 0; }