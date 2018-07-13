//Uva-10010 沃尔多夫在哪里
//这题不是DFS...wa了好久....

#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXSIZE = 52;
#define scanf scanf_s;

char maps[MAXSIZE][MAXSIZE];
int n, m, len;
int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
string str;

bool searchkey(int x, int y)
{
    if (len == 1)
        return true;
    for (int i = 0; i < 8; i++)
    {
        int xxx = dir[i][0] + x;
        int yyy = dir[i][1] + y;
        if (xxx >= 0 && xxx < m && yyy >= 0 && yyy < n && str[1] == maps[xxx][yyy])
        {
            int j = 2;
            for (; j < len && str[j] == maps[xxx + (j - 1) * dir[i][0]][yyy + (j - 1) * dir[i][1]]; j++)
                ;
            if (j == len)
                return true;
        }
    }
    return false;
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        memset(maps, 0, sizeof(maps));
        //memset(visited, 0, sizeof(visited));
        cin >> m >> n;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> maps[i][j];
                if (maps[i][j] > 'Z')
                    maps[i][j] -= 32;
            }
        int counts;
        cin >> counts;
        for (int i = 0; i < counts; i++)
        {
            cin >> str;
            transform(str.begin(), str.end(), str.begin(), ::toupper);
            len = str.length();
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (str[0] == maps[j][k])
                    {
                        if (searchkey(j, k))
                        {
                            cout << j + 1 << " " << k + 1 << endl;
                            j = n;
                            k = m;
                        }
                    }
                }
            }
        }
        if (N != 0)
            cout << endl;
    }
    return 0;
}