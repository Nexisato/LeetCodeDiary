#include <bits/stdc++.h>
using namespace std;
/**
 * @brief 
 * 
 * 
 */

class Solution {
public:
    string maskPII(string s) {
        string res = "";
        bool isEmail = false;
        if (s.find('@') != s.npos)
            isEmail = true;        
        if (isEmail) {
            int idx1 = 0, idx2 = 0;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] == '@') {
                    idx1 = i;
                }
                if (s[i] == '.')
                    idx2 = i;
                s[i] = (s[i] <= 'Z' && s[i] >= 'A') ? char(s[i] + 32) : s[i];
            }
            res += s[0];
            res += "*****";
            res += s[idx1 - 1];
            res += s.substr(idx1, (s.length() - idx1));

        } else {
            int digitCount = 0;
            for (int i = s.length() - 1; i >= 0; --i) {
                if (s[i] >= '0' && s[i] <= '9') {
                    ++digitCount;
                    if (res.length() < 4)
                        res += s[i];
                }
            }
            res += "-***-***";
            if (digitCount == 11)
                res += "-*+";
            else if (digitCount == 12)
                res += "-**+";
            else if (digitCount == 13)
                res += "-***+";
            reverse(res.begin(), res.end());

        }
        return res;
    }
private:
    vector<string> country = {"", "+*-", "+**-", "+***-"};

    string maskPII_shorter(string s) {
        string res;
        int at = s.find("@");
        if (at != string::npos) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            return s.substr(0, 1) + "*****" + s.substr(at - 1);
        }
        s = regex_replace(s, regex("[^0-9]"), "");
        return country[s.size() - 10] + "***-***-" + s.substr(s.size() - 4);

    }
};
int main() {
    char a = 'a', A = 'A';
    char b = 'b', B = 'B';
    cout << a - A << endl;
    cout << b - B << endl;


    return 0;
}