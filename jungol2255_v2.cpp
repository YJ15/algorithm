/**************************************************************
Problem: jungol2255
User: emsw2013
Language: C++
Result: Time Limit Exceed(93)
Time:10 ms
Memory:1 MB
****************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long gcd(long a, long b)
{
	return b ? gcd(b, a%b) : a;
}

long lcm(long a, long b)
{
	return a / gcd(a, b)*b;
}

int main()
{
	// 1. get input
	int N;										// ī�� ���� (1~20,000)
	vector<int> progression;			// ���� 
	vector<bool> visit;					// true: Ž���� ���� (Ž���� ���� �ߺ����� ����)
	map<int, bool> tracePairs;		// key: ī�� �� ���� (���� ���� lcm �ߺ����� ����)
	int lcmTrace = 1;						// ������ ���� ���� = return 
	int count = 0;							// ī���� �� �� ��� (1 ~ 2,000,000,000)

	cin >> N;
	visit.reserve(N);
	progression.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> progression[i];
		progression[i]--;

		if (progression[i] == i)
		{
			count++;
		}
	}

	// 2. search
	if (count == N) // ī�� ��ġ�� ������ ��� ��ġ�� �Է� �Ÿ���
	{
		cout << 0;
		return 0;
	}
	else
	{
		count = 0;
		for (int i = 0; i < N; i++) // card 1, ..., N
		{
			int idx = i;
			count = 0;

			if (progression[i] != i)  // ī�� ��ȣ�� ������ ��ġ�� ��� ������ 0�̹Ƿ� �Ÿ�
			{
				do
				{
					idx = progression[idx]; 
					count++;
					visit[idx] = true;
					if (visit[progression[idx]]) break; 
				} while (idx != i);

				// lcm
				if (tracePairs[count] == false) 
				{
					lcmTrace = lcm(lcmTrace, count); 
				}
				tracePairs[count] = true;
			}
		}
	}

	cout << lcmTrace; // 1 ~ 2,000,000,000

	return 0;
}