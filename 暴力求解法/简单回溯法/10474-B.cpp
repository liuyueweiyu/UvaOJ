//Uva-10474
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
#include<map>
#include<stack>
#include <algorithm>
using namespace std;
const int MAXSIZE = 10010;

int maps[MAXSIZE];
int query[MAXSIZE];

int main() {
	int n, q;
	int counter = 1;
	scanf("%d %d", &n, &q);
	while (n != 0 || q != 0) {
		printf("CASE# %d:\n", counter++);
		memset(maps, 0, sizeof(maps));
		memset(query, 0, sizeof(query));
		for (int i = 0; i < n; i++)
			scanf("%d", &maps[i]);
		for(int i = 0;i<q;i++)
			scanf("%d", &query[i]);
		sort(maps, maps + n);
		for (int i = 0; i < q; i++) {
			int pos = lower_bound(maps, maps + n, query[i]) - maps;
			if(maps[pos] == query[i])
				printf("%d found at %d\n", query[i], pos + 1);
			else
				printf("%d not found\n", query[i]);
		}
		scanf("%d %d", &n, &q);
	}

	return 0;
}