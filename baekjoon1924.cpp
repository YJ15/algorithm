   /**************************************************************
Problem: น้มุ 1924 2007ณโ
Language: C++
Time: 0 ms
Code Length: 552 B
Memory: 1988 KB
****************************************************************/
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
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
	y%=7;
	if (y == 1) cout << "MON";
	else if (y == 2) cout << "TUE";
	else if (y == 3) cout << "WED";
	else if (y == 4) cout << "THU";
	else if (y == 5) cout << "FRI";
	else if (y == 6) cout << "SAT";
	else  cout << "SUN";
	return 0;
}