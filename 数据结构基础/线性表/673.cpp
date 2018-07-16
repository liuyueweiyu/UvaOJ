//Uva-673
//注意空串，wa了好几次= =

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
int N;
string str;
int main() {

	cin >> N;
	cin.get();
	while (N--)
	{
		getline(cin, str);
		//cin >> str;
		stack<char> s;
		int len = str.length(), i;
		for (i = 0; i < len ; i++) {
			if (str[i] == '(' || str[i] == '[')
				s.push(str[i]);
			else {
				if (s.empty()) {
					s.push(str[i]);
				}
				else if ((str[i] == ')' && s.top() == '(') ||(str[i] == ']' && s.top() == '['))
					s.pop();
			}
		}
		if (s.empty() )
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}