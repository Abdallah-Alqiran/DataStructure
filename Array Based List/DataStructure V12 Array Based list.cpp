#include <iostream>

using namespace std;

class Array
{
	int* arr;
	int size;
	int length;

public:
	Array(int s = 10)
	{
		arr = new int[abs(s)];
		size = s;
		length = 0;
	}

	// check if the array empty
	bool isEmpty()
	{
		return length == 0;
	}
	// check if the array is full
	bool isFull()
	{
		return length == size;
	}

	// print all elements
	void print()
	{
		for (int i = 0; i < length; ++i)
			cout << arr[i] << ' ';
	}

	// insert element at position
	void insertAt(int pos, int element)
	{
		if (isFull())
			cout << "The Array is Full!";
		else
		{
			pos--;
			if (pos < 0 || pos > length)
			{
				cout << "Out of Range!";
			}
			else
			{
				for (int i = pos; i < length; ++i)
				{
					arr[i+1] = arr[i];
				}
				arr[pos] = element;
				length++;
			}
		}
	}

	// insert element at the end
	void insertAtEnd(int element)
	{
		if (isFull())
		{
			cout << "The Array is Full!";
			return;
		}
		arr[length] = element;
		length++;
	}

	// insert element at the begin
	void insertAtBegin(int element)
	{
		if (isFull())
		{
			cout << "The Array is Full!";
			return;
		}
		for (int i = length; i > 0; --i)
		{
			arr[i] = arr[i - 1];
		}
		
		arr[0] = element;
		length++;
	}

	// change the element at specific position
	void updateAt(int pos, int element)
	{
		pos--;
		if (pos < 0 || pos > length)
		{
			cout << "Out of Range!";
			return;
		}
		arr[pos] = element;
	}

	// insert element at the end if it's first time to appear
	void insertNoDuplicateAtEnd(int element)
	{
		if (isFull())
		{
			cout << "The Array is Full!";
			return;
		}
		for (int i = 0; i < length; ++i)
		{
			if (arr[i] == element)
			{
				cout << "the element " << element << " is exist\n";
				return;
			}
		}
		
		insertAtEnd(element);
	}

	// clear the array (not exactly)
	void clear()
	{
		length = 0;
	}

	// get the array size
	void getSize()
	{
		cout << length;
	}
	
	// get element at position
	void getElement(int pos)
	{
		pos--;
		if (pos < 0 || pos > length)
		{
			cout << "Out of Range!";
			return;
		}
		cout << arr[pos];
	}

	// when the programm finish delete the array
	~Array()
	{
		delete [] arr;
	}

};

int main()
{
	Array a;

	a.insertAt(1,5);
	a.insertAtEnd(7);
	a.insertAtEnd(8);
	a.insertAtBegin(2);
	a.insertAtBegin(2);
	a.updateAt(2,12);
	a.insertNoDuplicateAtEnd(21);
	a.getSize();

	a.print();
}
