//Uva-10361 自动作诗机
//水题，不过get了getline的用法

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
const int MAXSIZE = 52;
int main()
{
    int N;
    cin >> N;
    getchar();
    while (N--)
    {
        string str1, str2;
        //gets(str1);
        getline(cin, str1);
        int len = str1.length();
        int mark[4];
        for (int i = 0, j = 0; i < len; i++) ///line1
            if (str1[i] == '<' || str1[i] == '>')
                mark[j] = i, j++;
            else
                cout << str1[i];
        cout << endl;
        getline(cin, str2);
        ///line2
        for (int i = 0; str2[i] != '.'; i++)
            cout << str2[i];
        for (int j = 2; j >= 0; j--)
            for (int i = mark[j] + 1; i < mark[j + 1]; i++)
                cout << str1[i];
        for (int i = mark[3] + 1; i < len; i++)
            cout << str1[i];
        cout << endl;
    }
    return 0;
}