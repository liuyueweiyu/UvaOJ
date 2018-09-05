//Uva-548 树

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
int inorder[MAXSIZE];
int postorder[MAXSIZE];
int _ans = 10010;
int _sum = 1e9;

struct Node
{		
	int value;
	Node* left;
	Node* right;
};

void buid(int in_s, int in_e, int post_s, int post_e,Node* root,int sum) {
	if (in_s > in_e) {		//空树
		free(root);
		root = NULL;
		return;
	}
	if (in_s == in_e) {		//叶子节点
		root->value = inorder[in_s];
		if (sum + root->value < _sum) {	//判断是否为最小的路径
			_ans = root->value;
			_sum = sum + root->value;
		}
		if (sum + root->value == _sum)	//判断多条最小路径叶子节点最小的值
			_ans = min(_ans, root->value);
		return;
	}
	int i = in_s;
	root->value = postorder[post_e];
	while (inorder[i++] != postorder[post_e]);
	i--;
	root->left = (Node *)malloc(sizeof(Node));
	root->right = (Node *)malloc(sizeof(Node));
	root->left->left = NULL; root->left->right = NULL;
	root->right->left = NULL; root->right->right = NULL;
	buid(in_s, i - 1, post_s, post_s + i - in_s - 1,root->left,sum + root->value);	//建立左子树
	buid(i + 1, in_e, post_s + i - in_s, post_e - 1, root->right, sum + root->value);		//建立右子树

}

int main() {
	char ch;
	while (scanf("%d", &inorder[0]) != EOF)
	{
		_ans = 10010;
		_sum = 1e9;
		int counter = 1;
		while ((ch = getchar()) != '\n')
			scanf("%d", &inorder[counter++]);
		for (int i = 0; i < counter; i++)
			scanf("%d", &postorder[i]);
		Node* root = (Node *)malloc(sizeof(Node));
		buid(0, counter - 1, 0, counter - 1, root,0);
		cout << _ans << endl;
	}
	return 0;
}
