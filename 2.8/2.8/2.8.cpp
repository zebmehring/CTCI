#include <iostream>
#include "C:\Users\Zeb Mehring\Dropbox\Personal\C++\LinkedList\LinkedList\LinkedList.h"

template <typename T>
Node<T>* findLoop(Node<T> &head)
{
	Node<T> *slow = &head;
	Node<T> *fast = &head;
	while ((fast != NULL) && (fast->getNext() != NULL))
	{
		slow = slow->getNext();
		fast = fast->getNext()->getNext();
		if (slow == fast) break;
	}
	if (!fast || !fast->getNext()) return NULL;
	for (fast = &head; slow != fast; slow = slow->getNext(), fast = fast->getNext());
	return fast;
}

int main()
{
	Node<char> a('a');
	Node<char> b('b');
	Node<char> c('c');
	Node<char> d('d');
	Node<char> e('e');
	a.set(&b);
	b.set(&c);
	c.set(&d);
	d.set(&e);
	e.set(&c);

	Node<char> *start = findLoop(a);
	
	if(start) std::cout << start->getData() << std::endl;
	else std::cout << "Not a circular list!" << std::endl;
	std::cin.get();
}