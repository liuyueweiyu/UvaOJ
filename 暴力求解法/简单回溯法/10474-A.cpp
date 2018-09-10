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
		sort(maps, maps + n);		//排序
		
		for (int i = 0; i < q; i++) {		//二分查找query[i]的位置
			int num = query[i];		
			int _start = 0, _end = n-1, _mid;
			while (_start<= _end)
			{
				_mid = (_start + _end) / 2;
				if (maps[_mid] == num)
					break;
				else if(maps[_mid] < num)
					_start = _mid + 1;
				else
					_end = _mid - 1;
			}
			if (maps[_mid] == num) {
				while (maps[_mid - 1] == num && _mid >= 1)	//多个query[i]取第一个的位置
					_mid--;
				printf("%d found at %d\n", num, _mid + 1);
			}
			else
				printf("%d not found\n", num);
		}
		scanf("%d %d", &n, &q);
	}
	return 0;
}