//Uva-401 回文数
//字符数组的巧妙运用XDD 看到的时候这个解法真的很巧妙！

#include<iostream>
#include<string>
#include<map>
using namespace std;


string strtemp = "A***3**HIL*JM*O***2TUVWXY5";
string numtemp = "1SE*Z**8*";

char getMirror(char m) {
	if (m >= 'A' && m <= 'Z')
		return strtemp[m - 'A'];
	else
		return numtemp[m - '1'];
}

int main() {

	string str;
	while (cin >> str)
	{
		int len = str.length() / 2;
		int length = str.length() - 1;
		bool m_flag = true, r_flag = true;
		for (int i = 0; i <= len; i++) {
			if (r_flag && str[i] != str[length - i])
				r_flag = false;
			if (m_flag && str[i] != getMirror(str[length - i]))
				m_flag = false;
		}
		if (!r_flag && !m_flag)
			cout << str << " -- is not a palindrome." << endl;
		if (r_flag && !m_flag)
			cout << str << " -- is a regular palindrome." << endl;
		if (!r_flag && m_flag)
			cout << str << " -- is a mirrored string." << endl;
		if (r_flag && m_flag)
			cout << str << " -- is a mirrored palindrome." << endl;
		cout << endl;
	}

	return 0;
}