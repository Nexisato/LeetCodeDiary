/*
Description:
There are N students in a class. Some of them are friends, while some are not. 
Their friendship is transitive in nature. For example, if A is a direct friend of B, 
and B is a direct friend of C, then A is an indirect friend of C. 
And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. 
If M[i][j] = 1, then the ith and jth students are direct friends with each other, 
otherwise not. And you have to output the total number of friend circles among all the students.

Constraints:
1 <= N <= 200
M[i][i] == 1
M[i][j] == M[j][i]
*/
#include<bits/stdc++.h>
using namespace std;


/*
思路：DFS or BFS 直接得结果
*/
class Solution_DFS {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> visited(M.size(),false);
        int count=0;
        for(int i=0;i<M.size();i++)
            if(visited[i]==false){
                visited[i]=true;
                DFS(M,visited,i);
                count++;
            }
        return count;
    }
    void DFS(vector<vector<int>>& M, vector<bool>& visited, int i){
        for(int j=0;j<M.size();j++)
            if(M[i][j]==1 && visited[j]==false){
                visited[j]=true;
                DFS(M,visited,j);
            }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> visited(M.size(),false);
        int count=0;
        queue<int> q;
        for(int i=0;i<M.size();i++)
            if(visited[i]==false){
                q.push(i);
                while(!q.empty()){
                    int tmp=q.front();
                    visited[tmp]=true;
                    q.pop();
                    for(int j=0;j<M.size();j++){
                        if(M[tmp][j]==1 && visited[j]==false)
                            q.push(j);
                    }
                }
                count++;
            }
        return count;
    }
    
};

int main(){

    return 0;
}