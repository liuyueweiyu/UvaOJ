#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
#include<map>
#include<stack>
#include <algorithm>
using namespace std;
const int MAXSIZE = 65;
char str[MAXSIZE];
int main() {
	int N;
	cin >> str;
	while (strcmp(str,"#") != 0)
	{
		int len = strlen(str);
		if (!next_permutation(str, str + len))
			printf("No Successor\n");
		else
			cout << str << endl;
		cin >> str;
	}
	return 0;
}