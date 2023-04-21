#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int calcDayOfYear(string day, const vector<int>& prefixSum) {
        int month = stoi(day.substr(0, 2));
        int date = stoi(day.substr(3));
        return prefixSum[month - 1] + date;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> dateOfMonths({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
        vector<int> prefixSum(1, 0);
        for (int date : dateOfMonths) {
            prefixSum.push_back(date + prefixSum.back());
        }
        int arriveA = calcDayOfYear(arriveAlice, prefixSum), leaveA = calcDayOfYear(leaveAlice, prefixSum);
        int arriveB = calcDayOfYear(arriveBob, prefixSum), leaveB = calcDayOfYear(leaveBob, prefixSum);
        return max(0, (min(leaveA, leaveB) - max(arriveA, arriveB)) + 1);
    }
};
int main() {

    return 0;
}