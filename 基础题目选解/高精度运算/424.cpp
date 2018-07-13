//Uva-424 整数查询

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
#include<map>
#include <algorithm>
using namespace std;
const int MAXSIZE = 1000;


int main() {
	string str;
	int sum[MAXSIZE] = { 0 };
	while (cin >> str)
	{
		if (str == "0")
			break;
		int len = str.length();
		for (int i = 0; i < len; i++) {
			int num = str[len - i - 1] - 48;
			sum[i + 1] += (sum[i] + num) / 10;
			sum[i] = (sum[i] + num) % 10;
		}
	}
	int i;
	for (i = MAXSIZE - 1; i >= 0; i--)if (sum[i])break;	//忽略前导0
	for (; i >= 0; i--)cout << sum[i];					
	cout << endl;
	return 0;
}
