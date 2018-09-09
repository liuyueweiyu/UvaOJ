//Uva-10167
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
#include<map>
#include<stack>
#include <algorithm>
using namespace std;
const int MAXSIZE = 55;


struct Point
{
	int x;
	int y;
}points[MAXSIZE];

int main() {
	int N;
	scanf("%d", &N);
	while (N){
		int N2 = 2 * N;
		for (int i = 0; i < N2; i++)
			scanf("%d %d", &points[i].x, &points[i].y);
		
		for (int i = -500; i <= 500; i++) {
			for (int j = -500; j <= 500; j++)
			{	
				bool line = false;
				int counter = 0;
				for (int k = 0; k < N2; k++) {
					if (points[k].x*i + points[k].y*j == 0) {
						line = true;
						break;
					}
					else if (points[k].x*i + points[k].y*j > 0)
						counter++;
				}
				if (line)
					continue;
				if (counter == N) {
					printf("%d %d\n", i, j);
					i = j = 501;
				}
					
				
			}
		}

		scanf("%d", &N);

	}
	return 0;
}