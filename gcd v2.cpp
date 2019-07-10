#include <iostream>
#include <algorithm>
using namespace std;
int gcd1(int a, int b);
int gcd2(int a, int b);
int gcd3(int a, int b);
int main(void)
{
	// gcd
	int a, b, c;
	//scanf("%d %d", &a, &b);
	scanf("%d %d %d", &a, &b, &c);
	cout << gcd1(a, b) << endl;
	cout << gcd2(a, b) << endl;
	cout << gcd3(a, b) << endl;
	
	// �� ���� �ִ� ����� (N���� ���� ��������)
	cout << gcd2(gcd2(a, b), c) << endl;
	cout << gcd2(a, gcd2(b, c)) << endl;
	cout << gcd2(b, gcd2(a, c)) << endl;

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

// ��Ŭ���� ȣ����: GCD(a,b)=GCD(b,a%b)
int gcd2(int a, int b) // O(logN)
{
	cout << "a:" << a << ", b:" << b << endl;
	if (b == 0)  return a; // ���⼭ b == r, a==b
	return gcd2(b, a%b);
}
//input : 52 64
//a:52, b:64
//a:64, b:52
//a:52, b:12
//a:12, b:4
//a:4, b:0
//4

int gcd3(int a, int b) // O(logN)
{
	while (b != 0)
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