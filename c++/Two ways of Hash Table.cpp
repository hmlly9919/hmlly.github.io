#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef struct QNode
{
	int data;
	QNode* next;
	int success;
}QNode, *Queue;

Queue InitQueue()
{
	Queue head = new QNode;
	head->data = 0;
	head->next = nullptr;
	head->success = 0;
	return head;
}

bool EnQueue(Queue head, int data)
{
	int count = 1;
	Queue p;
	for (p = head; p->next != nullptr; p = p->next)
	{
		count++;
	}
	Queue q = new QNode;
	q->data = data; q->next = nullptr; q->success = count;
	p->next = q;
	return true;
}

int GetKeyNumber()
{
	int number_of_keys = 0;
	cout << "Please enter the number of the keys: " << endl;
	cin >> number_of_keys;
	return number_of_keys;
}

int GetKeys(int *key, int num)
{
	int i = 1;
	while (num--)
	{
		cout << "Please enter the key: " << endl;
		cin >> key[i++];
	}
	return 0;
}

int GetMod()
{
	int mode = 0;
	cout << "Please enter the mod for hash table: " << endl;
	cin >> mode;
	return mode;
}

int Hash1(int mode, int *key, int num)
{
	int ht1[100] = { 0 };
	int success[100] = { 0 }; int count;
	int failure[100] = { 0 };
	int index = 0;
	int su = 0;
	int fa = 0;
	for (int i = 1; i <= num; i++)
	{
		count = 1;
		index = key[i] % mode;
		while (ht1[index] != 0)
		{
			count++;
			index = (index + 1) % mode;
		}
		ht1[index] = key[i];
		success[index] = count;
	}
	for (int i = 0; i <= mode; i++)
	{
		if (ht1[i] == 0)
			failure[i] = 1;
		else
		{
			int j = i;
			while (ht1[j] != 0)
			{
				failure[i]++;
				j = (j + 1) % mode;
			}
			failure[i]++;
		}
	}
	for (int k = 0; k < mode; k++)
	{
		cout << k << "\t";
	}
	cout << endl;
	for (int k = 0; k < mode; k++)
	{
		cout << ht1[k] << "\t";
	}
	cout << endl;
	for (int k = 0; k < mode; k++)
	{
		cout << success[k] << "\t";
		su += success[k];
	}
	cout << endl;
	for (int k = 0; k < mode; k++)
	{
		cout << failure[k] << "\t";
		fa += failure[k];
	}
	cout << endl << static_cast<double>(su) / num << endl << static_cast<double>(fa) / mode << endl;
	return 0;
}

int Hash2(int mode, int *key, int num)
{
	int index = 0;
	int failure[100] = { 1 };
	int su = 0, fa = 0;
	Queue ht2[100] = { nullptr };
	for (int i = 0; i < mode; i++)
	{
		ht2[i] = InitQueue();
	}
	for (int i = 1; i <= num; i++)
	{
		index = key[i] % mode;
		EnQueue(ht2[index], key[i]);
	}
	for (int i = 0; i < mode; i++)
	{
		cout << "Index: ";
		cout << i << "    ";
		cout << "Data: ";
		Queue q = ht2[i]->next;
		Queue p = ht2[i]->next;
		if (q != nullptr)
		{
			for (; q != nullptr; q = q->next)
			{
				cout << q->data << "    ";
				su += q->success;
			}
		}
		else
		{
			cout << "NULL";
		}
		cout << "    ";
		cout << "Success: ";
		if (p != nullptr)
		{
			for (; p != nullptr; p = p->next)
			{
				cout << p->success << "    ";
				if (p->next == nullptr)
				{
					failure[i] = p->success + 1;
				}
			}
		}
		else
		{
			cout << "0";
			failure[i] = 1;
		}
		cout << "    ";
		cout << "Failure: ";
		cout << failure[i] << endl;
		fa += failure[i];
		cout << endl;
	}
	cout << endl << static_cast<double>(su) / num << endl << static_cast<double>(fa) / mode << endl;
	return 0;
}

int main()
{
	int num = GetKeyNumber();
	int key[100] = { 0 };
	GetKeys(key, num);
	int mode = GetMod();
	//Hash1(mode, key, num);
	//Hash2(mode, key, num);
	cin.get();
	cin.get();
	cin.get();
	return 0;
}