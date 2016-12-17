#include <iostream>

using namespace std;

struct CircularListElement
{
	int value;
	CircularListElement *next;
};

void addElement(CircularListElement *&position, int value)
{
	auto newElement = new CircularListElement;
	newElement->value = value;
	newElement->next = position->next;
	position->next = newElement;
	position = position->next;
}

void createList(CircularListElement *&head, int numberOfElements)
{
	head = new CircularListElement;
	head->value = 1;
	head->next = head;
	CircularListElement *position = head;

	for (int i = 2; i <= numberOfElements; i++)
	{
		addElement(position, i);
	}
}

void removeElement(CircularListElement *&head, CircularListElement *&removingPosition)
{
	auto oldElement = removingPosition->next;
	removingPosition->next = removingPosition->next->next;
	if (oldElement == head)
	{
		head = removingPosition->next;
	}
	delete oldElement;
}

void deleteList(CircularListElement *&head)
{
	while (head->next != head)
	{
		removeElement(head, head);
	}
	delete head;
}

int result(CircularListElement *&head, int m)
{
	CircularListElement *removingPosition = head;

	while (head->next != head)
	{
		for (int i = 0; i < m - 2; i++)
		{
			removingPosition = removingPosition->next;
		}
		removeElement(head, removingPosition);
		removingPosition = removingPosition->next;
	}

	return head->value;
}

bool tests()
{
	CircularListElement *head1 = nullptr;
	createList(head1, 5);

	CircularListElement *head2 = nullptr;
	createList(head2, 7);

	CircularListElement *head3 = nullptr;
	createList(head3, 3);

	return (result(head1, 2) == 3 && result(head2, 3) == 4 && result(head3, 3) == 2);
}

int main()
{
	setlocale (LC_ALL, "Russian");

	if (!tests())
	{
		cout << "Ошибка" << endl;
		return 0;
	}

	cout << "Введите число войнов: ";
	int n = 0;
	cin >> n;

	cout << "Введите m такое, что убивают каждого m-того: ";
	int m = 0;
	cin >> m;

	CircularListElement *head = nullptr;

	createList(head, n);

	cout << "Выигрышная позиция: " << result(head, m) << endl;

	deleteList(head);
	
	return 0;
}