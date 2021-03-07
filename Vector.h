#pragma once
#include <iostream>

using namespace std;

template <class T>
class SimpleVevtor
{
private:
	T* arptr;
	int arSize;
	void subError() const;
public:
	SimpleVevtor(int);
	SimpleVevtor(const SimpleVevtor&);
	~SimpleVevtor();
	int Size() const
	{
		return arSize;
	}
	T& operator[](int);
	void print() const;
	void push_back(int);
	void pop_back();

};

template <class T>
class SearchableVector : public SimpleVevtor<T>
{
public:
	SearchableVector(int s) : SimpleVevtor<T>(s) { }
	SearchableVector(const SimpleVevtor<T>& obj) : SimpleVevtor<T>(obj) {}
	SearchableVector(SimpleVevtor<T>& obj) : SimpleVevtor<T>(obj) {}
	int finditem(T item, T begin, T last);
};

template <class T>
class SortableVector : public SimpleVevtor<T>
{
public:
	SortableVector(int s) : SimpleVevtor<T>(s) { }
	SortableVector(const SimpleVevtor<T>& obj) : SimpleVevtor<T>(obj) {}
	SortableVector(SimpleVevtor<T>& obj) : SimpleVevtor<T>(obj) {}
	void sorting();
	
};



template<class T>
void SimpleVevtor<T>::subError() const
{
	cout << "ERROR: Subscript out of range. \n";
	exit(0);
}
template<class T>
SimpleVevtor<T>::SimpleVevtor(int s)
{
	arSize = s;
	arptr = new T[s];
		for (int i = 0; i < arSize; i++)
		{
			arptr[i] = T();
		}
}

template<class T>
 SimpleVevtor<T>::SimpleVevtor(const SimpleVevtor& obj)
{
	 arSize = obj.arSize;
	 arptr = new T[arSize];
	 for (int i = 0; i < arSize; i++)
	 {
		 arptr[i] = obj.arptr[i];
	 }
}

 template<class T>
 SimpleVevtor<T>::~SimpleVevtor()
 {
	 if (arSize < 0)
	 {
		 delete[] arptr;
	 }
 }

 template<class T>
  T& SimpleVevtor<T>::operator[](int sub)
 {

	 if (sub < 0 || sub >> arSize)
	 {
		 subError();
	 }
	 return arptr[sub];
 }

  template<class T>
   void SimpleVevtor<T>::print() const
  {
	   for (int i = 0; i < arSize; i++)
	   {
		   cout << arptr[i] << " ";
	   }
	   cout << endl;
  }

   template<class T>
   void SimpleVevtor<T>::push_back(int newnum)
   {
	   for (int i = 0; i < arSize; i++)
	   {
		   arptr[i] = arptr[i + 1];
		   arptr[arSize] = newnum;
	   }
	   
   }

   template<class T>
   void SimpleVevtor<T>::pop_back()
   {
	   for (int i = 0; i < arSize; i++)
	   {
		   arptr[i] = arptr[i + 1];
		   arptr[arSize] = NULL;
	   }
   }

   template<class T>
   int SearchableVector<T>::finditem(T item, T begin, T last)
    {
	   int mid;
	   if (last >= begin)
	   {
		   mid = (begin + last) / 2;
		   if (this->operator[](mid) == item)
		   {
			   return mid + 1;
		   }
		   else if (this->operator[](mid) < item)
		   {
			   return finditem(item,mid + 1, last);
		   }
		   else
		   {
			   return finditem(item,begin, mid - 1 );
		   }

	   }
	   return -1;
		  
   }

   template<class T>
   void SortableVector<T>::sorting()
   {  int temp;
	   for (int i = 0; i < this->Size(); i++)
	   {
		  for (int j = 0; j < this->Size()-1; j++)
		   {
			   if (this->operator[](j) > this->operator[](j + 1))
			   { 
				   temp = this->operator[](j);
				   this->operator[](j) = this->operator[](j+1);
				   this->operator[](j+1) = temp;
			   }
			   
		   }
	   }
   }


