/**************************************************************
Problem: ���� 2839 ���� ���
Language: C++14
Time: 0 ms
Code Length: 922 B
Memory: 1988 KB
****************************************************************/
// �������� ���� ������ �Ʒ��� ����
// (1) 5 kg ������ ����
// (2) 5 kg �� 3kg �������� ����
// (3) 3 kg ������ ����
// �׷��Ƿ� ���������� ���� ���̸� 
// (1), (2), (3)�� �ش���� �ʴ� ���� 
// ���԰� �� �������� �ʴ� ����̹Ƿ� -1�� ����Ѵ�.
#include <iostream>
using namespace std;
int main()
{
	// ���� ���� �Է�
	int sugerWeight;
	scanf("%d", &sugerWeight);

	int totalBagNumber = -1; // ���԰� �� �������� �ʴ� ��� -1

	// (1) 5 kg ������ ����
	if (sugerWeight % 5 == 0)
	{
		totalBagNumber = (sugerWeight / 5);
	}	
	// �� �� ������
	else 
	{
		int bagNumber5kg = sugerWeight / 5;
		int reminder = sugerWeight % 5;

		// 5 kg �� ���� ���� �������� ����
		// �׷��Ƿ� 5 kg �� ���� ���� �������� 5kg�� 0���� (=3kg������ ������) ������ üũ�Ѵ�.
		for (int bagNubmer5kg_changed = bagNumber5kg; 0 <= bagNubmer5kg_changed; bagNubmer5kg_changed--)
		{
			if (reminder % 3 == 0) 
			{	
				totalBagNumber = bagNubmer5kg_changed + (reminder / 3); // ���� 5kg ������ + 3 kg ������
				break;
			}
			reminder += 5; // 5 kg ���� 1�� ��
		}
	}
	cout << totalBagNumber << endl;
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �Ʒ��� �ڵ�� ���� ó�� Ǭ ������ �����ߴ�.
// �������, 97�� �� (5 kg 17�� + 3 kg 4�� = 21��) �� �����ε�,
// (5 kg 2�� + 3 kg 29�� = 31��) �� ���Ǿ���.
// 5 kg�� 3 kg ���� �� 5 kg �� ���� ���ƾ� �������� ������, �� �κ��� �����Ǿ���.
int main_FailCode()
{
	// ���� ���� �Է�
	int sugerWeight, sugerWeightCopy;
	scanf("%d", &sugerWeight);
	sugerWeightCopy = sugerWeight;

	int totalBagNumber = 0;
	// (1) 5 kg ������ ����
	if (sugerWeight % 5 == 0)
	{
		totalBagNumber = (sugerWeight / 5);
	}	
	else 
	{
		// (2) 5 kg �� 3kg �������� ����
		while (1)
		{
			// ���� 1�� �߰� (5 kg �������� �������� ����)
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
				// (3) 3 kg ������ ����
				if (sugerWeight % 3 == 0)
				{
					totalBagNumber = sugerWeight / 3;
				}
				// ���԰� ��Ȯ�ϰ� �� �������� ���� �Ǵ� (-1)
				else
				{
					totalBagNumber = -1; 
				}
				break;
			}
			totalBagNumber++; // ���� 1�� �߰���

			// 2. ���� Ȯ��
			if (sugerWeightCopy == 0) 
			{
				// ���԰� �� �������� ��� ���� ī��Ʈ ����
				break; 
			}
			if (sugerWeightCopy % 3 == 0)
			{
				// 3 kg �� ����� ���� ��� 3 kg �������� ī��Ʈ�� �߰��ϰ� ����
				totalBagNumber += (sugerWeightCopy / 3);
				break;
			}
		}
	}
	cout << totalBagNumber << endl;
	return 0;
}
