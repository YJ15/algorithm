/**************************************************************
Problem: น้มุ 1924 2007ณโ
Language: C++
Time: 0 ms
Code Length: 408 B
Memory: 1988 KB
****************************************************************/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string week[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

	int x, y;
	scanf("%d %d", &x, &y);
	for (int i=1; i<x; i++)
	{
		if (i == 2)
		{
			y += 28;
		}
		else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
		{
			y += 31;
		}
		else
		{
			y += 30;
		}
	}
	cout << week[y%7];
	return 0;
}