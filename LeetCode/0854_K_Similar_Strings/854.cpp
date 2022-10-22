#include <bits/stdc++.h>
using namespace std;
/*
思路：BFS / A*

*/
using pis = pair<int, string>;
class Solution {
private:
    vector<string> nextS(string& s, string& s2) {
        int i = 0, n = s.size();
        vector<string> res;
        while (s[i] == s2[i]) ++i;
        for (int j = i + 1; j < n; ++j) {
            if (s[j] == s2[i] && s[j] != s2[j]) {
                swap(s[i], s[j]);
                res.emplace_back(s);
                swap(s[i], s[j]);
            }
        }
        return res;
    }
    int f(string& s1, string& s2) {
        int count = 0;
        for (int i = 0; i < s1.length(); ++i)
            count += (s1[i] != s2[i]);
        return (count + 1) >> 1;
    }
public:
    int kSimilarity(string s1, string s2) {
        queue<string> q({s1});
        unordered_set<string> visited({s1});
        int res = 0;
        while (true) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                string s = q.front();
                q.pop();
                if (s == s2)
                    return res;
                for (auto & next : nextS(s, s2)) 
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
            }
            ++res;
        }
        return res;
    }
    int kSimilarity_A(string s1, string s2) {
        priority_queue<pis, vector<pis>, greater<pis>> q;
        q.push({f(s1, s2), s1});
        unordered_map<string, int> dist;
        dist[s1] = 0;
        while (true) {
            auto [_, s] = q.top();
            q.pop();
            if (s == s2)
                return dist[s];
            for (auto& next : nextS(s, s2)) {
                if (!dist.count(next) || dist[next] > dist[s] + 1) {
                    dist[next] = dist[s] + 1;
                    q.push({(dist[next] + f(next, s2)), next});
                }
            }
        }
    }
};
int main() {


    return 0;
}