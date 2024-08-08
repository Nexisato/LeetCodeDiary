#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;


// 通过 stringstream 分割字符串
vector<string> split(const string& str, char delim) {
    vector<string> res;
    if (str.empty()) 
        return res;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) {
        res.push_back(token);
    }
    return res;
}

// 通过 stringstream 合并字符串
string join(const vector<string>& vec, char delim) {
    if (vec.empty()) 
        return "";
    stringstream ss;
    for (int i = 0; i < vec.size() - 1; i++) {
        ss << vec[i] << delim;
    }
    ss << vec.back();
    return ss.str();
}


int main() {



    return 0;
}