#include <iostream>
#include <cstdio>
using namespace std;

const int KB = 1 << 10;
const int MB = 1 << 20;
const int GB = 1 << 30;

int main() {
    int n;
    cin >> n;

    double res = 0;
    if (n < KB) {
        res = (double)n;
        printf("%.2fB\n", res);
    } else if (KB <= n && n < MB) {
        res = (double)n / KB;
        printf("%.2fKB\n", res);
    } else if (MB <= n && n < GB){
        res = (double)n / MB;
        printf("%.2fMB\n", res);
    } else {
        res = (double)n / GB;
        printf("%.2fGB\n", res);
    }


    return 0;
}