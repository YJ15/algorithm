/**************************************************************
Problem: ���� 1026 ����
User: whfod2
Language: C++
Time: 0 ms
Code Length: 472 B
Memory: 1988 KB
****************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;
int main() // 1
{
	int N;
	scanf("%d", &N);

	int A[50];
	int B[50];

	for(int i = 0; i < N; i++) 
 	{ 
         scanf("%d", &A[i]); 
	}
	for(int i = 0; i < N; i++) 
 	{ 
         scanf("%d", &B[i]); 
	}

	sort(A, A + N);
	sort(B, B + N);

	int S = 0;
	for(int i = 0; i < N; i++) 
 	{
		S += (A[i] * B[N - 1 - i]); // ���� ������ X ���� ū��
	}

	cout << S;
	return 0;
}

