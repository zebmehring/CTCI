#include <stack>
#include <iostream>

template <class T>
class myQueue {
private:
	std::stack<T> s1;
	std::stack<T> s2;
public:
	void shift();
	void enqueue(T item);
	void dequeue();
	T front();
	int size();
};

template <class T>
void myQueue<T>::shift()
{
	if (s2.empty())
	{
		while (!s1.empty()) {
			int temp = s1.top();
			s1.pop();
			s2.push(temp);
		}
	}
}

template <class T>
void myQueue<T>::enqueue(T item)
{
	s1.push(item);
}

template <class T>
void myQueue<T>::dequeue()
{
	shift();
	std::cout << "Dequeueing: " << s2.top() << std::endl;
	s2.pop();
}

template <class T>
T myQueue<T>::front()
{
	shift();
	return s2.top();
}

template <class T>
int myQueue<T>::size()
{
	return s1.size() + s2.size();
}

int main()
{
	myQueue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.dequeue();
	q.dequeue();
	q.enqueue(0);
	q.dequeue();
	q.dequeue();
	q.dequeue();

	std::cin.get();
}