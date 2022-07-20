// ADT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Array
{
	int size;
	int length;
	int* items;

public:
	Array(int arraySize)
	{
		items = new int[arraySize];
		size = arraySize;
		length = 0;
	}
	void Fill(int filledSize)
	{

	 for (int i = 0; i < filledSize; i++)
	 {
		 cout << "Enter Item Number " << i << endl;
		 cin >> items[i];
		 length++;
	 }
	
	}
	void Display()
	{
		for (int i = 0; i < length; i++)
		{
			cout << items[i] << "\t";
		}
		cout << endl;
	}
	
	int getSize()
	{
		return size;
	}
	int getLength()
	{
		return length;
	}
	void Append(int newItem)
	{
		items[length] = newItem;
		length++;
	}
	void Insert(int index , int newItem)
	{
		for (int i = length; i > index; i--)
		{
			items[i] = items[i - 1];
			
	    }
		items[index] = newItem;  
		length++;
	}
	void Delete( int index)
	{
		for (int i = index; i < length; i++)
		{
			items[i] = items[i + 1];

		}
		length--;
	}
	bool Search(int item)
	{
		bool found = false;
	 for(int i=0; i < length; i++)
	 {
		 if (items[i] == item)
			 found = true;
	 }

	 return found;
	}

	void Enlarge(int newSize)
	{
		size = newSize;
		int* old = items;
		items = new int[newSize];
		for (int i = 0; i < length; i++)
		{
			items[i] = old[i];
		}
		delete[] old;
	}
	void Merge(Array another)
	{
		int i;
		int newSize = size + another.getSize();
		size = newSize;
		int* old = items;
		items = new int[newSize];
		for ( i = 0; i < length; i++)
		{
			items[i] = old[i];
		}
		delete[] old;
		int j = i;

		for (int i =0; i < another.getLength(); i++)
		{
			items[j++] = another.items[i];
			length++;
		}
		
	}
};
int main()
{
	int newSize;
	cout << "Enter the New Size of the Array " << endl;
	cin >> newSize;
	Array arr(newSize);
	int filledSize;
	cout << "How many elemnts do you want to fill \n";
	cin >> filledSize;
	arr.Fill(filledSize);
	cout << "array size " << arr.getSize() << " ";
	cout << "And Filled Elements are = " << arr.getLength() << endl;
	arr.Display();
	int newItem;
	//cout << "Enter A number to append \n";
	//cin >> newItem;
	//arr.Append(newItem);
	cout << "Insert New Item \n";
	cin >> newItem;
	arr.Insert(2, newItem);
	arr.Display();
	int deleted;
	cout << "Enter the index of an item to be deleted \n";
	cin >> deleted;
	arr.Delete(deleted);
	arr.Display();
	int searchedItem;
	cout << "Enter a number to search For \n";
	cin >> searchedItem;

	if(arr.Search(searchedItem))
	cout << searchedItem << " Is Exist \n";
	else
		cout << searchedItem << " Is not Found \n";
	Array another(4);
	another.Fill(3);
	arr.Merge(another);
	cout << "array size " << arr.getSize() << " ";
	cout << "And Filled Elements are = " << arr.getLength() << endl;
	arr.Display(); 

  return 0;
}