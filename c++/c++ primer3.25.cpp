#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<int> v1{ 42, 65, 95, 100, 39, 67, 95, 76, 88, 76, 83, 92, 76, 93 };
	vector<int> score(11, 0);
	for (auto iter1 = v1.cbegin(); iter1 != v1.cend(); iter1++ )
	{
		auto iter2 = score.begin();
		(*(iter2 + (*iter1 / 10)))++;
	}
	for (auto iter2 = score.cbegin(); iter2 != score.cend(); iter2++)
	{
		cout << *iter2 << " ";
	}
	cout << endl;
	cin.get();
	return 0;
}