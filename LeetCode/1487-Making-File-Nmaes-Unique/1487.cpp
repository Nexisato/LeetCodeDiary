#include <bits/stdc++.h>
using namespace std;

/*
思路：不能只思考 pureName，括号是个无底洞

若文件系统中不存在名为 name 的文件夹，直接创建即可
否则 从 k = 1 开始，尝试使用添加后缀 k 的新文件名创建新文件夹
*/
class Solution {
private:
    string addSuffix(string name, int k) {
        return name + '(' + to_string(k) + ')';
    }
public:
    vector<string> getFolderNames(vector<string>& names) {
        int n = names.size();
        vector<string> res;
        unordered_map<string, int> nameTable;
        // for (int i = 0; i < n; ++i) {
        //     string folderName = names[i];
        //     int nameL = folderName.length();
        //     for (int charIndex = 0; charIndex < folderName.length(); ++charIndex)
        //         if (folderName[charIndex] == '(') {
        //             nameL = charIndex;
        //             break;
        //         }
        //     string pureName = folderName.substr(0, nameL);
        //     res[i] = pureName;
        //     if (++nameTable[pureName] > 1) {
        //         int count = nameTable[pureName] - 1;
        //         if (folderName[folderName.length() - 1] == ')') {
        //             int originNum = atoi(folderName.substr(nameL + 1, folderName.length() - 1).c_str());
        //             count = max(count, originNum);
        //         }             
        //         res[i] += '(' + to_string(count) + ')';
        //     }
        //     else
        //         res[i] = folderName;

        // }
        for (const auto& name : names) {
            if (!nameTable.count(name)) {
                res.emplace_back(name);
                nameTable[name] = 1;
            } else {
                int k = nameTable[name];
                while (nameTable.count(addSuffix(name, k))) ++k;
                res.emplace_back(addSuffix(name, k));
                nameTable[name] = k + 1; //此处是为了减少重复遍历次数
                nameTable[addSuffix(name, k)] = 1;
            }
        }
        return res;
    }
};
int main() {
    Solution ss;
    //vector<string> names({"pes","fifa","gta","pes(2019)"});
    vector<string> names({"onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece", "onepiece"});
    vector<string> res = ss.getFolderNames(names);
    for (const auto& s : res)
        cout << s << endl;

    return 0;
}