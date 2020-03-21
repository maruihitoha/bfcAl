#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GetCoinNum(vector<int> coinVec, int sum, int num) 
{

	if (sum == 0) 
	{
		return 0;
	}

	int result = INT_MAX;

	for (int i = 0; i < num; i++) 
	{

		if (coinVec[i] <= sum) 
		{
			result = min(result, GetCoinNum(coinVec, sum - coinVec[i], num) + 1);
		}

	}
	return result;
}

int main()
{
	int money;
	int num;
	string strInput;
	string str = "";
	vector<int> coinVec;


	cout << "바꾸고자 하는 액수 입력 : ";
	cin >> money;
	getchar();

	cout << "동전을 입력하시오(공백으로 구분, 엔터로 입력 종료) : ";
	getline(cin, strInput);
	cout << endl;


	for (int i = 0; i < strInput.length(); i++) 
	{
		if (strInput.at(i) == ' ') 
		{
			coinVec.push_back(atoi(str.c_str()));
			str = "";
		}
		else 
		{
			str += strInput.at(i);
			continue;
		}
	}
	coinVec.push_back(atoi(str.c_str()));

	num = coinVec.size();

	cout << GetCoinNum(coinVec, money, num) << endl;


	

}

