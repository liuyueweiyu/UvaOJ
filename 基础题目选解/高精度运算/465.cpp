//Uva-465
//atof这个解法真是太牛批了

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
const int MAXSIZE = 1000;

int main()
{
    char str1[MAXSIZE], str2[MAXSIZE];
    char sign;
    while (cin >> str1 >> sign >> str2)
    {
        cout << str1 << " " << sign << " " << str2 << endl;
        if (atof(str1) > 2147483647)
            cout << "first number too big" << endl;
        if (atof(str2) > 2147483647)
            cout << "second number too big" << endl;
        double x;
        if (sign == '*' && atof(str1) * atof(str2) > 2147483647 || sign == '+' && atof(str1) + atof(str2) > 2147483647)
            cout << "result too big" << endl;
    }

    return 0;
}