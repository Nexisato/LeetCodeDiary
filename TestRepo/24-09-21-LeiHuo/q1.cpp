#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(10, 0));
    vector<int> games(10, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        int total = 0;
        int vote_count = 0;
        for (int j = 0; j < 10; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] >= 1)
                ++total;
            if (arr[i][j] == 2)
                ++vote_count;
        }
        if (total < 3) continue;
        if (vote_count > 5 || vote_count > total - 2) continue;
        for (int j = 0; j < 10; ++j) {
            if (arr[i][j] == 2) {
                ++games[j];
            }
        }
    }
    int max_game = *max_element(games.begin(), games.end());
    
    vector<int> res_arr;
    for (int i = 0; i < 10; ++i)
        if (games[i] == max_game) {
            res_arr.push_back(i + 1);
        }

    if (res_arr.size() == 1) {
        cout << res_arr[0] << endl;
    } else {
        for (int i = 0; i < res_arr.size(); ++i) {
            if (i > 0)
                cout << " ";
            cout << res_arr[i];
        }
        cout << endl;
    }



    return 0;
}