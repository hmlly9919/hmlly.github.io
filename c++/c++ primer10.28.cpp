#include<iostream>
#include<functional>
#include<algorithm>
#include<iterator>
#include<vector>
#include<list>

using namespace std;
using namespace std::placeholders;

int main()
{
	vector<int> integers{ 1,2,3,4,5,6,7,8,9 };
	list<int> ivec1, ivec2, ivec3;
	copy(integers.cbegin(), integers.cend(), front_inserter(ivec1));
	copy(integers.cbegin(), integers.cend(), back_inserter(ivec2));
	copy(integers.cbegin(), integers.cend(), inserter(ivec3, ivec3.begin()));
	for (auto num : ivec1)
	{
		cout << num << " ";
	}
	cout << endl;
	for (auto num : ivec2)
	{
		cout << num << " ";
	}
	cout << endl;
	for (auto num : ivec3)
	{
		cout << num << " ";
	}
	cout << endl;
	cin.get();
	return 0;
}