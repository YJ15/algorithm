/**************************************************************
Problem: ���� 1085 ���簢������ Ż��
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

	if ((w / 2) < x) { // right (left �� ���� x �״��)
		x = w - x;
	}

	if ((h / 2) < y) { // top (bottom �� ���� y �״��)
		y = h - y;
	}

	if (x < y) cout << x;
	else cout << y;

	return 0;
}