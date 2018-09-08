//Uva-10596
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
#include<map>
#include<stack>
#include <algorithm>
using namespace std;
const int MAXSIZE = 205;

int maps[MAXSIZE][MAXSIZE] = { 0 };
int deg[MAXSIZE] = { 0 };
int n, m;
bool visit[MAXSIZE] = { false };


void euler(int u) {
	visit[u] = true;
	for (int i = 0; i < n; i++) {
		if (!visit[i] && maps[u][i] == 1) {
			maps[u][i] = maps[i][u] = 0;
			euler(i);
		}
	}
}

int main() {
	while (scanf("%d %d", &n,&m) != EOF){
		if (n == 0) {
			cout << "Not Possible" << endl;
			continue;
		}
		memset(deg, 0, sizeof(deg));
		memset(maps, 0, sizeof(maps));
		memset(visit, 0, sizeof(visit));
		bool flag = true;
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			maps[x][y] = maps[y][x] = 1;
			deg[x]++,deg[y]++;
		}
		for (int i = 0; i < n; i++) {
			if (deg[i] % 2 != 0) {
				flag = false;
				break;
			}
		}
		if (!flag || n < 2 || m < 2) {
			cout << "Not Possible" << endl;
		}
		else{
			for (int i = 0; i < n; i++)
				if (deg[i] != 0) {
					euler(i);
					break;
				}
			for (int i = 0; i < n; i++)
				if (deg[i] !=0 &&  !visit[i])
					flag = false;
			if (!flag)
				cout << "Not Possible" << endl;
			else
				cout << "Possible" << endl;
		}



	}
	return 0;
}
