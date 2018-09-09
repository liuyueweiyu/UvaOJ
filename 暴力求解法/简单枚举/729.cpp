//Uva-729
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
int maps[MAXSIZE];
int main() {
	int N;
	cin >> N;
	while (N--)
	{
		int a, b;
		cin >> a >> b;
		memset(maps, 0, sizeof(maps));
		for (int i = 0; i < b; i++)
			maps[a - i - 1] = 1;
		do
		{
			for (int i = 0; i < a; i++) {
				printf("%d", maps[i]);
			}
			printf("\n");
		} while (next_permutation(maps,maps+a));

		if (N)
			printf("\n");
	}

	return 0;
}