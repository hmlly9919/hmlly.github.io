#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<int> v1{ 1, 2, 3, 4, 10, 5, 6, 7, 8 };
	int sum = 0;
	for (auto iter1 = v1.begin(), iter2 = v1.end() - 1; iter1 <= iter2; iter1++, iter2--)
	{
		sum = *iter1 + *iter2;
		cout << sum << " ";
	}
	cout << endl;
	cin.get();
	return 0;
}