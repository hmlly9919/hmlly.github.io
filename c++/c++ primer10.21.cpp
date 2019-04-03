#include<iostream>

using namespace std;

int main()
{
	int p = 100;
	auto f = [p]() mutable ->bool
	{
		return --p;
	};
	cout << f() << endl;
	cin.get();
	return 0;
}