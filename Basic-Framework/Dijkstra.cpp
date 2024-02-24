/*
 * @Date: 2024-02-20 09:20:44
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0000-Basic-Framework/Dijkstra.cpp
 * @Description:
 */
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstra_raw(vector<vector<int>>& graph, int start) {
	int n = graph.size();
	vector<int> dist(n, INT_MAX);
	vector<bool> visited(n, false);
	dist[start] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1;
		int minDist = INT_MAX;
		for (int j = 0; j < n; j++) {
			if (!visited[j] && dist[j] < minDist) {
				u = j;
				minDist = dist[j];
			}
		}
		if (u == -1)
			break;
		visited[u] = true;
		for (int v = 0; v < n; v++) {
			if (!visited[v] && graph[u][v] != INT_MAX) {
				dist[v] = min(dist[v], dist[u] + graph[u][v]);
			}
		}
	}
	return dist;
}

vector<int> dijkstra_opt(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, start});
    while (!minHeap.empty()) {
        auto [d, u] = minHeap.top();
        minHeap.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INT_MAX && dist[v] > dist[u] + graph[u][v]) {
                dist[v] = dist[u] + graph[u][v];
                minHeap.push({dist[v], v});
            }
        }
    }
    return dist;

}


int main() { 
    vector<int> dist;
    vector<vector<int>> graph = {
        {0, 5, INT_MAX, 10},
        {INT_MAX, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };
    dist = dijkstra_opt(graph, 0);
    for (int i = 0; i < dist.size(); i++)
        cout << dist[i] << " ";
    cout << endl;

    
    
    return 0; 
}
