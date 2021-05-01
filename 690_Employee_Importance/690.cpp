/*
LeetCode 690: Employee Importance
@Description:
You are given a data structure of employee information, which includes the employee's unique id, 
their importance value and their direct subordinates' id.

For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3. 
They have importance value 15, 10 and 5, respectively. 
Then employee 1 has a data structure like [1, 15, [2]], 
and employee 2 has [2, 10, [3]], 
and employee 3 has [3, 5, []]. 
Note that although employee 3 is also a subordinate of employee 1, the relationship is not direct.

Now given the employee information of a company, and an employee id, you need to return the total 
importance value of this employee and all their subordinates.

Note:
One employee has at most one direct leader and may have several subordinates.
The maximum number of employees won't exceed 2000.
*/
#include <bits/stdc++.h>
using namespace std;
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    /*
    思路：递归即可，时间复杂度略高
    */
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        int res = 0, idx = 0;
        for (int i = 0; i < n; ++i) {
            if (employees[i]->id == id) {
                res += employees[i]->importance;
                idx = i;
                break;
            }
        }
        for (int i = 0; i < employees[idx]->subordinates.size(); ++i)
            res += getImportance(employees, employees[idx]->subordinates[i]);
        return res;
    }
    /*
    思路：DFS/BFS
    */
    unordered_map<int, Employee*> table;
    int dfs(int id) {
        Employee* employee = table[id];
        int total = employee->importance;
        for (int subID : employee->subordinates)
            total += dfs(subID);
        return total;
    }
    int getImportance_dfs(vector<Employee*> employees, int id) {
        for (auto& employee : employees)
            table[employee->id] = employee;
        return dfs(id);
    }

    int getImportance_bfs(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for (auto& employee : employees)
            mp[employee->id] = employee;
        
        int res = 0;
        queue<int> q;
        q.push(id);
        while (!q.empty()) {
            int curID = q.front();
            q.pop();
            Employee* employee = mp[curID];
            res += employee->importance;
            for (auto& subID : employee->subordinates)
                q.push(subID);
        }
        return res;
    }

};
int main() {


    return 0;
}