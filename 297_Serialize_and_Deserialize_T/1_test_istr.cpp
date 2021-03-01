#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    istringstream istr;
    istr.str("1 56.7");
    //上述两个过程可以简单写成 istringstream istr("1 56.7");
    cout << istr.str() << endl;
    int a;
    float b;
    istr >> a;
    cout << a << endl;
    istr >> b;
    cout << b << endl;
    return 0;
}