#include <iostream>
#include "Vector.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	const int  Size = 10;
	int find;
	int num = 10;
	SearchableVector<int> Array(Size);
	SortableVector<int> Array1(Size);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < Size; i++)
	{
		Array[i] = i*2;
		Array1[i] = rand() % 100;
	}
	Array.print();
	find = Array.finditem(num,0,Size);
	if (find == -1)
	{
		cout << "Cannot find the number " << num << " in the array"<< endl;
	}
	else
	{
		cout << "The number " << num << " at index " << find << endl;
	}
	cout << "Before sorting: "; Array1.print();
	Array1.sorting();
	cout << "After sorting: "; Array1.print();
	Array1.push_back(99);
	cout << "After push back: "; Array1.print();
	Array1.pop_back();
	cout << "After pop_back: "; Array1.print();
	

	system("pause");
	return 0;
}