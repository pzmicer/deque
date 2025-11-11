#include "Deque.h"
#include "Deque.cpp"
#include <fstream>
#include <ctime>

int main()
{
	ifstream fin("in.txt");
	try
	{
		Deque<int> d;
		int a;
		while (!fin.eof())
		{
			fin >> a;
			//d.push_front(a);
			d.push_back(a);
		}
		cout << d << endl;
		d.Sort();
		cout << d << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}
	return 0;
}