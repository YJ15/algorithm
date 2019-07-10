#include <iostream>
#include <algorithm>
using namespace std;
int gcd1(int a, int b);
int gcd2(int a, int b);
int main(void)
{
	// gcd
	int a, b;
	scanf("%d %d", &a, &b);
	cout << gcd1(a, b) << endl;
	cout << gcd2(a, b) << endl;
	cout << gcd2(a, b) << endl;

	getchar();
	return 0;
}

int gcd1(int a, int b) // O(N)
{
	int g = 1;
	for (int n=2; n<=min(a,b); n++)
	{
		if ((a % n) == 0 && (b % n) == 0)
		{
			g = n;
		}
	}
	return g;
}

// 유클리드 호제법: GCD(a,b)=GCD(b,a%b)
int gcd2(int a, int b) // O(logN)
{
	cout << "a:" << a << ", b:" << b << endl;
	if (b == 0)  return a; // 여기서 b == r, a==b
	return gcd2(b, a%b)
};
//input : 52 64
//a:52, b:64
//a:64, b:52
//a:52, b:12
//a:12, b:4
//a:4, b:0
//4

int gcd3(int a, int b) // O(logN)
{
	while (b == 0)
	{
		cout << "a:" << a << ", b:" << b << endl;
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}
//input : 52 64
//a:52, b:64
//a:64, b:52
//a:52, b:12
//a:12, b:4
//a:4, b:0
//4