#include <iostream>
#define el '\n'

using namespace std;

class DoublyLinkedList
{
	struct Node
	{
		int item;
		Node* next, * prev;
	};
	Node* first, * last;
	int counter;

public:
	DoublyLinkedList()
	{
		first = last = NULL;
		counter = 0;
	}

	void insertFirst(int element)
	{
		Node *newNode = new Node;
		newNode->item = element;

		if (counter == 0)
		{
			first = last = newNode;
			newNode->prev = newNode->next = NULL;
		}
		else
		{
			first->prev = newNode;
			newNode->prev = NULL;
			newNode->next = first;
			first = newNode;
		}
		counter++;
	}
	void insertLast(int element)
	{
		if (counter == 0)
			insertFirst(element);
		else
		{
			Node* newNode = new Node;
			newNode->item = element;

			newNode->prev = last;
			last->next = newNode;
			last = newNode;
			newNode->next = NULL;

			counter++;
		}

	}

	void insertAtPos(int pos, int element)
	{
		pos--;
		if (pos > counter && pos < 0)
			cout << "Out of Range\n";
		else if (pos == counter)
			insertLast(element);
		else if (pos == 0)
			insertFirst(element);
		else
		{
			Node *newNode = new Node;
			newNode->item = element;

			Node* cur = first;
			
			for (int i = 1; i < pos; ++i)
			{
				cur = cur->next;
			}

			newNode->next = cur->next;
			newNode->prev = cur;
			cur->next->prev = newNode;
			cur->next = newNode;

			counter++;
		}
	}

	void removeAtFirst()
	{
		if (counter == 0)
			cout << "Nothing to Remove\n";
		else if (counter == 1)
		{
			delete first;
			first = last = NULL;

			counter--;
		}
		else
		{
			Node *del = first;
			first = first->next;
			first->prev = NULL;
			delete del;
			
			counter--;
		}
	}
	void removeAtLast()
	{
		if (counter == 0)
			cout << "Nothing to Remove";
		else if (counter == 1)
			removeAtFirst();
		else
		{
			Node* del = last;
			last = last->prev;
			last->next = NULL;
			delete del;

			counter--;
		}

	}

	void removeElement(int element)
	{
		Node* remove = first;
		if (element == remove->item)
			removeAtFirst();
		else
		{
			while (remove != NULL)
			{
				if (remove->item == element)
					break;
				remove = remove->next;
			}
			if (remove == NULL)
			{
				cout << "The element doesn't exist\n";
				return;
			}

			if (remove == last)
				removeAtLast();
			else
			{
				remove->prev->next = remove->next;
				remove->next->prev = remove->prev;
				delete remove;
				
				counter--;
			}
			
		}
	}
	void removeAtPos(int pos)
	{
		if (pos > counter && pos < 0)
		{
			cout << "Out of Range\n";
			return;
		}
		pos--;
		if (pos == 0)
			removeAtFirst();
		else if (pos == counter)
			removeAtLast();
		else
		{
			Node *cur = first;
			for (int i = 1; i <= pos; ++i)
				cur = cur->next;
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;

			delete cur;
			counter--;
		}

		
	}


	void display()
	{
		if (counter == 0)
		{
			cout << "Empty";
			return;
		}
		Node *cur = first;
		
		cout << "Elements ";

		while (cur != NULL)
		{
			cout << cur->item << ' ';
			cur = cur->next;
		}
		cout << '\n';
	}
	void displayReversed()
	{
		if (counter == 0)
		{
			cout << "Empty";
			return;
		}
		Node* cur = last;
		cout << "Elements Reversed ";
		while (cur != NULL)
		{
			cout << cur->item << ' ';
			cur = cur->prev;
		}
	}

	~DoublyLinkedList()
	{
		Node* temp = first;
		while (first != NULL)
		{
			temp = first;
			first = first->next;
			delete temp;
		}
		last = NULL;
		counter = 0;
	}

};

int main()
{
	DoublyLinkedList l;

	l.insertFirst(5);
	l.insertFirst(6);
	l.insertLast(7);
	l.insertAtPos(2,77);
	l.insertAtPos(1,55);
	l.removeAtFirst();
	l.removeElement(12);
	l.removeAtPos(2);

	l.display();
	l.displayReversed();
}
