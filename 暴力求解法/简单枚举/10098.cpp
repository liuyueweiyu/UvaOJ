#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
#include<map>
#include<stack>
#include <algorithm>
using namespace std;
const int MAXSIZE = 55;
char str[MAXSIZE];
int main() {
	int N;
	scanf("%d", &N);
	while (N--)
	{
		cin >> str;
		int len = strlen(str);
		sort(str, str + len);
		do
		{
			cout << str << endl;
		} while (next_permutation(str, str + len));
		cout << endl;
	}
	return 0;
}