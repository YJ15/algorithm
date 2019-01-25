/**************************************************************
    Problem: jungol2255
	User: emsw2013
    Language: C++
    Result: Time Limit Exceed(93)
    Time:1101 ms
    Memory:1 MB
****************************************************************/

#include <iostream>
#include <vector>
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
	int N;
	vector<int> progression;		// 수열 
	vector<long> trace;				// 위치 별 궤적 
	long count = 0;						// 카운팅 할 때 사용 (max 2,000,000,000)

	scanf("%d", &N);

	progression.resize(N);
	for(int i = 0; i < N; i++)
	{
        scanf("%d", &progression[i]);
		progression[i]--;
		if (progression[i] == i) 
		{
			count++;
		}
    }

	// 2. search
	if (count == N) 
	{
		cout << 0;
		return 0;
	}
	else 
	{
		count = 0;
		for (int i=0; i<N; i++)
		{
			int idx = i;
			count = 0;

			if (progression[i] != i)
			{
				do
				{
					idx = progression[idx];
					count++;
				}
				while (idx != i);

				if (find(trace.begin(), trace.end(), count) == trace.end()) 
				{
					trace.push_back(count);
				}
			}
		}
	}

	// 3. lcm
	long result = trace[0];
	for (int i = 1; i < trace.size(); i++)
	{
		result = lcm(result, trace[i]);
	}

	cout << result; // 1 ~ 2,000,000,000

	return 0;
}