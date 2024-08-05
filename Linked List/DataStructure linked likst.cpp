#include <iostream>
#define el '\n'

using namespace std;

class LinkedList
{
	struct Node
	{
		int item;
		Node* next;
	};
	Node* first = NULL, * last = NULL;
	int length = 0;

public:


	void insertFirst(int element)
	{
		Node* newNode = new Node;
		newNode->item = element;

		if (first == NULL)
		{
			first = last = newNode;
			newNode->next = NULL;
		}
		else
		{
			newNode->next = first;
			first = newNode;
		}
		length++;
	}

	void insertLast(int element)
	{
		Node* newNode = new Node;
		newNode->item = element;
		if (last == NULL)
		{
			last = first = newNode;
			newNode->next = NULL;
		}
		else
		{
			last->next = newNode;
			last = newNode;
			newNode->next = NULL;
		}
		length++;
	}

	void insertAtPos(int pos, int element)
	{
		pos--;
		if (pos<0 || pos > length)
			cout << "Out of Range";
		else if (pos == 0)
			insertFirst(element);
		else if (pos == length)
			insertLast(element);
		else
		{
			Node* newNode = new Node;
			newNode->item = element;
			Node* temp = first;

			for (int i = 1; i < pos; ++i)
				temp = temp->next;
			newNode->next = temp->next;
			temp->next = newNode;
			length++;
		}

	}
	void print()
	{
		Node* temp = first;

		while (temp != NULL)
		{
			cout << temp->item << ' ';
			temp = temp->next;
		}
	}

	void removeFirst()
	{
		Node* temp = new Node;
		temp = first;

		if (length == 0)
			cout << "Nothing to Remove";
		else if (length == 1)
		{
			first = last = NULL;
			delete temp;
			length--;
		}

		else
		{
			first = first->next;
			delete temp;
			length--;
		}
	}

	void removeLast()
	{
		Node* temp1 = new Node;
		Node* temp2 = new Node;
		temp1 = first->next;
		temp2 = first;

		if (length == 0)
		{
			cout << "Nothing to Remove";
			return;
		}

		else if (length == 1)
		{
			first = last = NULL;
			delete temp1;
			length--;
		}
		else
		{
			while (temp1 != NULL)
			{
				temp2 = temp1;
				temp1 = temp1->next;
			}
			delete temp1;
			temp2->next = NULL;
			last = temp2;
			length--;
		}
	}

	void removeElement(int element)
	{
		bool test = false;
		Node* temp1 = first->next;
		Node* temp2 = first;

		if (temp2->item == element)
		{
			removeFirst();
			return;
		}

		while (temp1 != NULL)
		{
			if (temp1->item == element)
			{
				test = true;
				break;
			}
			temp2 = temp1;
			temp1 = temp1->next;
		}
		if (!test)
		{
			cout << "The element you want to find didn't exist";
			return;
		}
		
		if (temp1 == NULL)
		{
			removeLast();
		}
		else
		{
			temp2->next = temp1->next;
			delete temp1;
			length--;
		}
	}

	void removeAtPos(int pos)
	{
		pos--;
		if (pos<0 || pos > length)
		{
			cout << "Out of Range";
			return;
		}

		if (pos == 0)
			removeFirst();
		else if (pos == length)
			removeLast();
		else
		{
			Node* temp1 = first->next;
			Node* temp2 = first;

			for (int i = 1; i < pos; ++i)
			{
				temp2 = temp1;
				temp1 = temp1->next;
			}
			
			temp2->next = temp1->next;
			delete temp1;
		}

	}

};

int main()
{

	LinkedList l;
	l.insertFirst(1);
	l.insertLast(10);
	l.insertLast(11);
	l.insertAtPos(1, 0);
	l.insertAtPos(5, 13);
	l.insertAtPos(4, 12);

	l.removeElement(1);
	l.insertFirst(1);

	l.removeElement(10);
	l.removeAtPos(2);

	l.print();

}
