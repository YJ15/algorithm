/**************************************************************
Problem: ���� 11719 �״�� ����ϱ�2
User: whfod2
Language: C++
Time: 4 ms
Code Length: 355 B
Memory: 1992 KB
****************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void)
{
	vector<string> values;
	string temp;
	while (getline(cin, temp)){
		//if (temp.empty()) break;
		values.push_back(temp);
		if (values.size() == 100) break;
	}

	for (int i=0; i<values.size(); i++){
		cout << values[i] << endl;
	}

	return 0;
}