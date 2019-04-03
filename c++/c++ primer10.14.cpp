#include<iostream>

using namespace std;

int main()
{
	auto f = [](int a, int b) ->int
	{
		return a + b;
	};
	cout << f(1, 3) << endl;
	cin.get();
	return 0;
}