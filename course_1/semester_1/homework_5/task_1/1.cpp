#include <iostream>

using namespace std;

struct ListElement
{
	int value;
	ListElement *next;
};

void addToHead(ListElement *&head, int value)
{
	auto newElement = new ListElement;
	newElement -> value = value;
	newElement -> next = head;
	head = newElement;
}

ListElement *additionPosition(ListElement *head, int value)
{
	ListElement *position = head;
	ListElement *previousPosition = nullptr;

	while (position != nullptr && value > position -> value)
	{
		previousPosition = position;
		position = position -> next;
	}

	return previousPosition;
}

void addElement(ListElement *position, int value)
{
	auto newElement = new ListElement;
	newElement -> value = value;
	newElement -> next = position -> next;
	position -> next = newElement;
}

void removeFromHead(ListElement *&head)
{
	ListElement *oldHead = head;
	head = head -> next;
	delete oldHead;
}

ListElement *removingPosition(ListElement *head, int value)
{
	ListElement *position = head;
	ListElement *previousPosition = nullptr;

	while (position != nullptr && position -> value != value)
	{
		previousPosition = position;
		position = position -> next;
	}
	
	return previousPosition;
}

void removeElement(ListElement *removingPosition)
{
	auto oldElement = removingPosition -> next;
	removingPosition -> next = removingPosition -> next -> next;
	delete oldElement;
}

void printAll(ListElement *head)
{
	while (head != nullptr)
	{
		cout << head -> value << " ";
		head = head -> next;
	}

	cout << endl;
}

void deleteList(ListElement *&head)
{
	while (head != nullptr)
	{
		removeFromHead(head);
	}
}

bool additionToHeadTest()
{
	ListElement *head1 = nullptr;
	ListElement *head2 = nullptr;

	addToHead(head1, 1);
	addToHead(head2, 2);

	return (head1 -> value == 1 && head2 -> value == 2); 
}

bool removingFromHeadTest()
{
	ListElement *head1 = nullptr;

	addToHead(head1, 1);
	addToHead(head1, 2);
	addToHead(head1, 3);

	removeFromHead(head1);

	return (head1 -> value == 2 && head1 -> next -> value == 1); 
}

bool additionPositionTest()
{
	ListElement *head1 = nullptr;

	addToHead(head1, 4);
	addToHead(head1, 2);
	addToHead(head1, 1);

	return (additionPosition(head1, 0) == nullptr && additionPosition(head1, 3) == head1 -> next);
}

bool removingPositionTest()
{
	ListElement *head1 = nullptr;

	addToHead(head1, 4);
	addToHead(head1, 2);
	addToHead(head1, 1);

	return (removingPosition(head1, 1) == nullptr && additionPosition(head1, 2) == head1);
}

bool additionTest()
{
	ListElement *head1 = nullptr;

	addToHead(head1, 1);
	addElement(additionPosition(head1, 3), 3);
	addElement(additionPosition(head1, 2), 2);

	return (head1 -> value == 1 && head1 -> next -> value == 2 && head1 -> next -> next -> value == 3); 
}

bool removingTest()
{
	ListElement *head1 = nullptr;

	addToHead(head1, 1);
	addToHead(head1, 2);
	addToHead(head1, 3);

	removeElement(removingPosition(head1, 2));

	return (head1 -> value == 3 && head1 -> next -> value == 1); 
}

bool tests()
{
	return (additionToHeadTest() && removingFromHeadTest() && additionPositionTest() && removingPositionTest() && additionTest() && removingTest());
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!tests())
	{
		cout << "Ошибка";
		return 0;
	}

	int command = 1;
	ListElement *head = nullptr;

	while (command != 0)
	{
		cout << "Введите команду: ";
		cin >> command;

		if (command == 0)
		{
			deleteList(head);
			return 0;
		}

		if (command == 1)
		{
			cout << "Введите значение элемента: ";
			int value = 0;
			cin >> value;
			
			if (head == nullptr)
			{
				addToHead(head, value);
			}
			else 
			{
				ListElement *a = additionPosition(head, value);
				if (a == nullptr)
				{
					addToHead(head, value);
				}
				else
				{
					addElement(a, value);
				}
			}
		}

		if (command == 2)
		{
			cout << "Введите значение элемента: ";
			int value = 0;
			cin >> value;

			ListElement *r = removingPosition(head, value);
			if (r != nullptr && r -> next == nullptr)
			{
				cout << "Заданного элемента не существует в списке" << endl;
			}
			else
			{
				if (r == nullptr)
				{
					removeFromHead(head);
				}
				else removeElement(r);
			}
		}

		if (command == 3)
		{
			printAll(head);
		}

		cout << endl;
	}
}