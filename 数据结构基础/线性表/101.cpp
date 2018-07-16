//Uva-101 木块问题
//没注意非法判定wa了好多次，sad

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
#include<map>
#include<stack>
#include <algorithm>
using namespace std;
const int MAXSIZE = 30;

struct Node
{
	int value;
	int pos;
};

stack<Node*> piles[MAXSIZE];
int N;
Node nodes[MAXSIZE];

void clear(stack<Node*>* pile,int value) {
	while (!pile->empty() && pile->top()->value != value)
	{
		int n = pile->top()->value;
		piles[n].push(&nodes[n]);	
		pile->top()->pos = n;
		pile->pop();

	}
}


void print() {
	stack<Node*> s;
	for (int i = 0; i < N; i++) {
		cout << i << ":";
		
		while (!piles[i].empty()) {
			s.push(piles[i].top());
			piles[i].pop();
		}
		while (!s.empty()) {
			cout << " " << s.top()->value;
			piles[i].push(s.top());
			s.pop();
		}
		cout << endl;
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		nodes[i].value = i;
		nodes[i].pos = i;
		piles[i].push(&nodes[i]);
	}
	string str1, str2;
	int start, end;
	cin >> str1;
	while (str1 != "quit")
	{
		cin >> start >> str2 >> end;
		if (nodes[start].pos == nodes[end].pos) {
			cin >> str1;
			continue;
		}
		if (str2 == "onto")
			clear(&piles[nodes[end].pos], end);
		if (str1 == "move") {
			clear(&piles[nodes[start].pos], start);
			piles[nodes[end].pos].push(piles[nodes[start].pos].top());
			piles[nodes[start].pos].pop();
			nodes[start].pos = nodes[end].pos;
		}
		if (str1 == "pile") {
			stack<Node*> pile;
			stack<Node*>* from = &piles[nodes[start].pos];
			stack<Node*>* to = &piles[nodes[end].pos];
			while (from->top()->value != start)
			{
				pile.push(from->top());
				from->pop();
			}
			pile.push(from->top());
			from->pop();
			while (!pile.empty()){
				pile.top()->pos = nodes[end].pos;
				to->push(pile.top());
				pile.pop();
			}
		}
		cin >> str1;
	}
	print();
	return 0;
}