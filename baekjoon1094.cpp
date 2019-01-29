/**************************************************************
Problem: 백준 1094 막대기
User: whfod2
Language: C++
Time:0 ms
Code Length: 1: 181 B / 2: 171 B
Memory:1988 KB
****************************************************************/
#include <iostream>
int main() // 1
{
	int x, cnt = 0;
	scanf("%d", &x);
	for (int i = 1; i <= x; i <<= 1)
	{
		if ((x & i) == i) cnt++;
	}
	printf("%d", cnt);
	return 0;
}

int main2() // 2
{
	int x, cnt = 0;
	scanf("%d", &x);
	while (0 < x)
	{
		if ((x % 2) == 1) cnt++;
		x>>=1;
	}
	printf("%d", cnt);
	return 0;
}