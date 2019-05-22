/**************************************************************
Problem: 백준 2839 설탕 배달
Language: C++14
Time: 0 ms
Code Length: 922 B
Memory: 1988 KB
****************************************************************/
// 봉지수가 적은 순서는 아래와 같다
// (1) 5 kg 만으로 구성
// (2) 5 kg 와 3kg 조합으로 구성
// (3) 3 kg 만으로 구성
// 그러므로 순차적으로 구할 것이며 
// (1), (2), (3)에 해당되지 않는 경우는 
// 무게가 딱 떨어지지 않는 경우이므로 -1을 출력한다.
#include <iostream>
using namespace std;
int main()
{
	// 설탕 무게 입력
	int sugerWeight;
	scanf("%d", &sugerWeight);

	int totalBagNumber = -1; // 무게가 딱 떨어지지 않는 경우 -1

	// (1) 5 kg 만으로 구성
	if (sugerWeight % 5 == 0)
	{
		totalBagNumber = (sugerWeight / 5);
	}	
	// 그 외 구성들
	else 
	{
		int bagNumber5kg = sugerWeight / 5;
		int reminder = sugerWeight % 5;

		// 5 kg 이 많을 수록 봉지수가 적다
		// 그러므로 5 kg 이 가장 많은 순서부터 5kg이 0개인 (=3kg만으로 구성됨) 순서로 체크한다.
		for (int bagNubmer5kg_changed = bagNumber5kg; 0 <= bagNubmer5kg_changed; bagNubmer5kg_changed--)
		{
			if (reminder % 3 == 0) 
			{	
				totalBagNumber = bagNubmer5kg_changed + (reminder / 3); // 남은 5kg 봉지수 + 3 kg 봉지수
				break;
			}
			reminder += 5; // 5 kg 봉지 1개 뺌
		}
	}
	cout << totalBagNumber << endl;
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 아래의 코드는 가장 처음 푼 것으로 실패했다.
// 예를들어, 97일 때 (5 kg 17개 + 3 kg 4개 = 21개) 가 정답인데,
// (5 kg 2개 + 3 kg 29개 = 31개) 가 계산되었다.
// 5 kg과 3 kg 조합 시 5 kg 가 가장 많아야 봉지수가 적은데, 이 부분이 누락되었다.
int main_FailCode()
{
	// 설탕 무게 입력
	int sugerWeight, sugerWeightCopy;
	scanf("%d", &sugerWeight);
	sugerWeightCopy = sugerWeight;

	int totalBagNumber = 0;
	// (1) 5 kg 만으로 구성
	if (sugerWeight % 5 == 0)
	{
		totalBagNumber = (sugerWeight / 5);
	}	
	else 
	{
		// (2) 5 kg 와 3kg 조합으로 구성
		while (1)
		{
			// 봉지 1개 추가 (5 kg 많을수록 봉지수가 적음)
			if (5 < sugerWeightCopy)
			{
				sugerWeightCopy -= 5;
			}
			else if (3 < sugerWeightCopy)
			{
				sugerWeightCopy -= 3;
			}
			else
			{
				// (3) 3 kg 만으로 구성
				if (sugerWeight % 3 == 0)
				{
					totalBagNumber = sugerWeight / 3;
				}
				// 무게가 정확하게 안 떨어지는 경우로 판단 (-1)
				else
				{
					totalBagNumber = -1; 
				}
				break;
			}
			totalBagNumber++; // 봉지 1개 추가됨

			// 2. 무게 확인
			if (sugerWeightCopy == 0) 
			{
				// 무게가 딱 떨어지는 경우 봉지 카운트 종료
				break; 
			}
			if (sugerWeightCopy % 3 == 0)
			{
				// 3 kg 의 배수만 남은 경우 3 kg 봉지수를 카운트에 추가하고 종료
				totalBagNumber += (sugerWeightCopy / 3);
				break;
			}
		}
	}
	cout << totalBagNumber << endl;
	return 0;
}
