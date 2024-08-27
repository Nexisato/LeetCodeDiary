/**
 * 别搞这么麻烦，但是这题真没有你想的那么容易
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;


string num2words(int num) {
    string res = "";
    vector<string> beforeTwenty({"", "One", "Two", "Three", "Four", "Five", "Six",
    "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
    "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"});
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> threeBound = {"", "Thousand", "Million", "Billion"};

    int idx = 0;
    while (num > 0) {
        if (num % 1000 > 0) {
            int cur = num % 1000;
            string tmp = "";
            if (cur >= 100) {
                tmp += beforeTwenty[cur / 100] + " Hundred ";
                cur %= 100;
            }
            if (cur >= 20) {
                tmp += tens[cur / 10] + " ";
                cur %= 10;
            }
            if (cur > 0) {
                tmp += beforeTwenty[cur] + " "; 
            }
            if (!tmp.empty()) {
                tmp += threeBound[idx];
            }
            res = tmp + " " + res;
        }
        num /= 1000;
        ++idx;
    }

    return string(res.begin(), res.end() - 1);
}


int main() {

    int num = 1010101;
    string res = num2words(num);
    cout << res << endl;


    return 0;
}
