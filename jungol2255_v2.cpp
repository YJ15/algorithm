/**************************************************************
Problem: jungol2255
User: emsw2013
Language: C++
Result: Success(100)
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
	int N;										// 카드 개수 (1~20,000)
	vector<int> progression;			// 수열 
	vector<bool> visit;					// true: 탐색한 궤적 (탐색한 궤적 중복연산 방지)
	map<int, bool> tracePairs;		// key: 카드 별 궤적 (같은 궤적 lcm 중복연산 방지)
	int lcmTrace = 1;						// 수열의 최종 궤적 = return 
	int count = 0;							// 카운팅 할 때 사용 (1 ~ 2,000,000,000)

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
	if (count == N) // 카드 위치와 수열이 모두 일치한 입력 거르기
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

			if (progression[i] != i)  // 카드 번호와 수열이 일치한 경우 궤적이 0이므로 거름
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
