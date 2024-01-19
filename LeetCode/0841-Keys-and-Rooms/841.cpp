/*
LeetCode 841: Keys and Rooms
@Description:
There are N rooms and you start in room 0.  Each room has a distinct number in 0, 1, 2, ..., N-1, 
and each room may have some keys to access the next room. 

Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] 
where N = rooms.length.  A key rooms[i][j] = v opens the room with number v.

Initially, all the rooms start locked (except for room 0). 

You can walk back and forth between rooms freely.

Return true if and only if you can enter every room.

Note:
1 <= rooms.length <= 1000
0 <= rooms[i].length <= 1000
The number of keys in all rooms combined is at most 3000.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：DFS模板题
*/
class Solution {
private:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int num) {
        if (visited[num])
            return;
        visited[num] = true;
        int size = rooms[num].size();
        for (int i = 0; i < size; ++i)
            dfs(rooms, visited, rooms[num][i]);
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();
        int count = 0;
        vector<bool> visited(N, false);
        dfs(rooms, visited, 0);
        for (auto vis : visited)
            if (vis)
                ++count;
        return (count == N);
    }
};
int main() {

    return 0;
}