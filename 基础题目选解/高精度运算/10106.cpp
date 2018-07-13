//Uva-10106 乘积
// 大数乘法

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
const int MAXSIZE = 1000;
int sum[MAXSIZE] = {0};
int num1[MAXSIZE] = {0};
int num2[MAXSIZE] = {0};
int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        memset(sum, 0, sizeof(sum));
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
        if (str1 == "0" || str2 == "0")
        {
            cout << "0" << endl;
            continue;
        }
        int len1 = str1.length();
        int len2 = str2.length();
        for (int i = 0; i < len1; i++)
            num1[i] = str1[len1 - i - 1] - 48;
        for (int i = 0; i < len2; i++)
            num2[i] = str2[len2 - i - 1] - 48;
        for (int i = 0; i < len1; i++)
            for (int j = 0; j < len2; j++)
            {
                int x = sum[i + j] + num1[i] * num2[j];
                sum[i + j] = x % 10;
                sum[i + j + 1] += x / 10;
            }
        int i;
        for (i = MAXSIZE - 1; i >= 0; i--)
            if (sum[i])
                break; //忽略前导0
        for (; i >= 0; i--)
            cout << sum[i];
        cout << endl;
    }
    return 0;
}