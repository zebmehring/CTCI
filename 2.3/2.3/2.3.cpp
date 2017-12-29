#include "C:\Users\Zeb Mehring\Dropbox\Personal\C++\LinkedList\LinkedList\Node.h"

template <typename T>
bool deleteNode(Node<T> *head)
{
	if (!head)
	{
		return false;
	}
	else if (!head->getNext())
	{
		delete head;
		return true;
	}
	else
	{
		head->set(head->getNext()->getData());
		head->set(head->getNext()->getNext());
		delete head->getNext();
		return true;
	}
}