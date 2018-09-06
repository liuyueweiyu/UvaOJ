//Uva-699
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
#include<map>
#include<stack>
#include <algorithm>
using namespace std;

const int MAXSIZE = 100000;
int inorder[MAXSIZE] = { 0 };
int sum[MAXSIZE] = { 0 };
int nowindex = 0;

void calc(int center){
	sum[center] += inorder[nowindex++];
	if (inorder[nowindex] != -1)		//判断左子树
		calc(center - 1);
	else
		nowindex++;
	if (inorder[nowindex] != -1)		//判断右子树
		calc(center + 1);
	else
		nowindex++;
	return;
}
int main() {
	char ch;
	int num = 1;
	scanf("%d", &inorder[0]);
	while (inorder[0] != -1)
	{
		memset(sum, 0, sizeof(sum));
		nowindex = 0;
		int counter = 1;
		while ((ch = getchar()) != '\n')
			scanf("%d", &inorder[counter++]);
		calc(MAXSIZE / 2);
		int i = 0;
		printf("Case %d:\n", num++);
		while (sum[i] == 0) i++;
		cout << sum[i++];
		while (sum[i] != 0)
			cout << " " << sum[i++];
		cout << endl << endl;
		scanf("%d", &inorder[0]);
	}
	return 0;
}