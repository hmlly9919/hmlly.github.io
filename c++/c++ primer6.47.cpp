#include<iostream>
#include<string>
#include<cassert>
#include<vector>

using namespace std;

bool ShowVectorInt(vector<int> num, int count)
{
	if (count < num.size())
	{
		cout << __FILE__ << ": in function " << __func__ << "at line :" << __LINE__ << ":    ";
		cout << num[count++] << endl;
		ShowVectorInt(num, count);
	}
	else
		return true;
	return true;
	
}

int main()
{
	vector<int> num{ 1,2,3,4,5,6,7,8,9,10 };
	int count = 0;
	ShowVectorInt(num, count);
	cin.get();
	return 0;
}