/*
Description:
Given two strings s and t , write a function to determine if t is an anagram of s.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash_1[26]={0},hash_2[26]={0};
        for(char c:s) hash_1[c-'a']++;
        for(char c:t) hash_2[c-'a']++;
        for(int i=0;i<26;i++)
            if(hash_1[i]!=hash_2[i]) return false;
        return true;
    }
};

int main(){
    string s1="anagram",s2="naagram";
    Solution ss;
    bool tmp=ss.isAnagram(s1,s2);
    cout<<tmp;
    return 0;
}