#include "C:\Users\Zeb Mehring\Dropbox\Personal\C++\LinkedList\LinkedList\LinkedList.h"

template <typename T>
Node <T>* intersectingLists(LinkedList<T> list1, LinkedList<T> list2)
{
	if (list1.isEmpty() || list2.isEmpty()) return NULL;
	
	while (list1.getLength() > list2.getLength()) list1.pop();
	while (list1.getLength() < list2.getLength()) list2.pop();

	while (!list1.isEmpty() && (list1.getHead() != list2.getHead()))
	{
		list1.pop();
		list2.pop();
	}

	return list1.getHead();
}