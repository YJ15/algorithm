/**************************************************************
Problem: 백준 1085 직사각형에서 탈출
User: whfod2
Language: C++
Time: 0 ms
Code Length: 258 B
Memory: 1984 KB
****************************************************************/
#include <iostream>
using namespace std;
int main() 
{
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	if ((w / 2) < x) { // right (left 일 때는 x 그대로)
		x = w - x;
	}

	if ((h / 2) < y) { // top (bottom 일 때는 y 그대로)
		y = h - y;
	}

	if (x < y) cout << x;
	else cout << y;

	return 0;
}