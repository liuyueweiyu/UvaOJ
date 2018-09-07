//Uva-572
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
#include<map>
#include<stack>
#include <algorithm>
using namespace std;
const int MAXSIZE = 1000;

char maps[MAXSIZE][MAXSIZE];
int n, m;
int _ans;
int dir[8][2] = {
	{ -1,-1},{ -1,0 },{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}
};

void dfs(int x,int y) {
	for (int i = 0; i < 8; i++) {
		int xxx = x + dir[i][0];
		int yyy = y + dir[i][1];
		if (xxx >= 0 && xxx < n && yyy >= 0 && yyy < m &&  maps[xxx][yyy] == '@') {
			maps[xxx][yyy] = '*';
			dfs(xxx, yyy);
		}
	}
}


int main() {
	scanf("%d %d", &n, &m);
	while (n != 0 && m != 0){
		getchar();
		_ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				scanf("%c", &maps[i][j]);
			getchar();
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (maps[i][j] == '@') {
					maps[i][j] = '*';
					dfs(i, j);
					_ans++;
				}
			}
		}
		if(n != 0 || m != 0)
		cout << _ans << endl;

		scanf("%d %d", &n, &m);



	}

	return 0;
}