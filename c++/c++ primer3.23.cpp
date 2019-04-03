#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<int> v1{ 1,2,3,55,66,77,89,23,2323,2323111 };
	for (auto iter = v1.begin(); iter != v1.end(); iter++)
	{
		(*iter) *= 2;
		cout << *iter << " ";
	}
	cout << endl;
	cin.get();
	return 0;
}