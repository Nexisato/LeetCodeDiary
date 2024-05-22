#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res(2, vector<int>());
        map<int, int> winner_table;
        map<int, int> loser_table;
        for (auto& match : matches) {
            int winner = match[0];
            int loser = match[1];
            winner_table[winner] += 1;
            loser_table[loser] += 1;
        }
        for (auto& [player, wins] : winner_table) {
            if (loser_table.count(player) == 0)
                res[0].push_back(player);
        }
        for (auto& [player, losses] : loser_table) {
            if (losses == 1)
                res[1].push_back(player);
        }
        return res; 
    }
};
int main() {


    return 0;
}