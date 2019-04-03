#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<string> str{ "hello", "fucking", "world", "", "yes" };
	for (auto iter = str.begin(); iter != str.end() && !iter->empty(); iter++)
	{
		auto first_char = iter->begin();
		*first_char = toupper(*first_char);
		cout << *iter << " ";
	}
	cin.get();
	return 0;
}